#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <set>
#include "graph.h"

using namespace std;
namespace fs = std::filesystem;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int wordCount;

    TrieNode() : isEndOfWord(false), wordCount(0) {}
};

class Trie {
public:
    Trie() : root(new TrieNode()) {}

    ~Trie() {
        deleteTrie(root);
    }

    void insert(const string& word) const {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
        node->wordCount++;
    }

    bool search(const string& word) const {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    int getWordCount(const string& word) const {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return 0;
            }
            node = node->children[c];
        }
        return node->isEndOfWord ? node->wordCount : 0;
    }

    vector<string> getSuggestions(const string& input) const {
        vector<string> suggestions;
        size_t pos = input.find_last_of(' ');
        string prefix;
        if (pos != string::npos) {
            prefix = input.substr(pos + 1);
        }
        else {
            prefix = input;
        }
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return suggestions; 
            }
            node = node->children[c];
        }
        collectSuggestions(node, prefix, suggestions);
        return suggestions;
    }

    TrieNode* root;

    void deleteTrie(TrieNode* node) {
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }

    void collectSuggestions(TrieNode* node, string currentWord, vector<string>& suggestions) const {
        if (node->isEndOfWord) {
            suggestions.push_back(currentWord);
        }
        for (auto& pair : node->children) {
            collectSuggestions(pair.second, currentWord + pair.first, suggestions);
        }
    }
};

namespace DSProject {
    struct TreeNode {
        string name;
        bool isFile;
        vector<TreeNode*> children;
        TreeNode* parent;
        Trie* trie;

        TreeNode(const string& n, bool file, TreeNode* p = nullptr) : name(n), isFile(file), parent(p), trie(nullptr) {
            if (isFile) {
                trie = new Trie();
            }
        }

        ~TreeNode() {
            for (auto child : children) {
                delete child;
            }
            delete trie;
        }

        string getPath() const {
            if (parent == nullptr) {
                return name;
            }
            return parent->getPath() + "\\" + name;
        }

        void loadFileContentToTrie() const {
            if (isFile && trie) {
                ifstream file(getPath());
                string line;
                while (getline(file, line)) {
                    istringstream iss(line);
                    string word;
                    while (iss >> word) {
                        trie->insert(word);
                    }
                }
                file.close();
            }
        }
    };

    class FileSystemTree {
    public:
        FileSystemTree(const string& rootPath) {
            root = new TreeNode(rootPath, false);
            buildTree(rootPath, root);
        }

        ~FileSystemTree() {
            delete root;
        }

        void printTree() const {
            printNode(root, 0);
        }

        string searchFile(const string& fileName) const {
            TreeNode* result = searchNode(root, fileName);
            if (result) {
                return result->getPath();
            }
            else {
                return "File not found";
            }
        }

        void searchWord(const string& query, vector<pair<string, int>>& resultPaths) const {
            if (query.find(" AND ") != string::npos) {
                vector<string> words = split(query, " AND ");
                searchWordInTrie(root, words[0], resultPaths, true);
                for (size_t i = 1; i < words.size(); ++i) {
                    vector<pair<string, int>> tempResults;
                    searchWordInTrie(root, words[i], tempResults, true);
                    intersectResults(resultPaths, tempResults);
                }
            }
            else if (query.find(" OR ") != string::npos) {
                vector<string> words = split(query, " OR ");
                for (const string& word : words) {
                    searchWordInTrie(root, word, resultPaths, false);
                }
                aggregateResults(resultPaths);
            }
            else {
                // Single word query
                searchWordInTrie(root, query, resultPaths, true);
            }
        }


        vector<string> getSuggestions(const string& prefix) const {
            vector<string> suggestions;
            collectSuggestions(root, prefix, suggestions);
            return suggestions;
        }

        string displayFileContent(const string& filepath) const {
            ifstream file(filepath);
            if (file.is_open()) {
                stringstream buffer;
                buffer << file.rdbuf();
                file.close();
                return buffer.str();
            }
            else {
                return "Unable to open file: " + filepath;
            }
        }

        string promptAndDisplayFileContent() const {
            cout << "Enter the filename (e.g., t1.txt): ";
            string fileName;
            cin >> fileName;
            return displayFileContent(fileName);
        }

        TreeNode* root;

        void buildTree(const string& path, TreeNode* node) {
            for (const auto& entry : fs::directory_iterator(path)) {
                if (entry.is_directory()) {
                    TreeNode* folderNode = new TreeNode(entry.path().filename().string(), false, node);
                    node->children.push_back(folderNode);
                    buildTree(entry.path().string(), folderNode);
                }
                else if (entry.path().extension() == ".txt") {
                    TreeNode* fileNode = new TreeNode(entry.path().filename().string(), true, node);
                    node->children.push_back(fileNode);
                    fileNode->loadFileContentToTrie();
                }
            }
        }

        void printNode(const TreeNode* node, int indent) const {
            for (int i = 0; i < indent; ++i) cout << "  ";
            cout << (node->isFile ? "File: " : "Folder: ") << node->name << endl;
            for (const auto& child : node->children) {
                printNode(child, indent + 1);
            }
        }

        TreeNode* searchNode(TreeNode* node, const string& fileName) const {
            if (node->isFile && node->name == fileName) {
                return node;
            }
            for (auto& child : node->children) {
                TreeNode* result = searchNode(child, fileName);
                if (result) {
                    return result;
                }
            }
            return nullptr;
        }

        void searchWordInTrie(TreeNode* node, const string& word, vector<pair<string, int>>& resultPaths, bool exactMatch) const {
            if (node->isFile && node->trie) {
                int count = node->trie->getWordCount(word);
                if (count > 0) {
                    resultPaths.emplace_back(node->getPath(), count);
                }
            }
            for (auto& child : node->children) {
                searchWordInTrie(child, word, resultPaths, exactMatch);
            }
        }

        void intersectResults(vector<pair<string, int>>& resultPaths, const vector<pair<string, int>>& tempResults) const {
            vector<pair<string, int>> intersected;
            set<string> tempPaths;
            for (const auto& [path, count] : tempResults) {
                tempPaths.insert(path);
            }
            for (const auto& [path, count] : resultPaths) {
                if (tempPaths.find(path) != tempPaths.end()) {
                    intersected.emplace_back(path, count);
                }
            }
            resultPaths = intersected;
        }

        void aggregateResults(vector<pair<string, int>>& resultPaths) const {
            unordered_map<string, int> pathCounts;
            for (const auto& [path, count] : resultPaths) {
                pathCounts[path] += count;
            }
            resultPaths.clear();
            for (const auto& [path, count] : pathCounts) {
                resultPaths.emplace_back(path, count);
            }
        }

        vector<string> split(const string& str, const string& delimiter) const {
            size_t start = 0;
            size_t end = str.find(delimiter);
            vector<string> result;
            while (end != string::npos) {
                result.push_back(str.substr(start, end - start));
                start = end + delimiter.length();
                end = str.find(delimiter, start);
            }
            result.push_back(str.substr(start));
            return result;
        }

        void collectSuggestions(TreeNode* node, const string& prefix, vector<string>& suggestions) const {
            if (node->isFile && node->trie) {
                size_t pos = prefix.find_last_of(' ');
                string lastWord;
                if (pos != string::npos) {
                    lastWord = prefix.substr(pos + 1);
                }
                else {
                    lastWord = prefix;
                }
                vector<string> fileSuggestions = node->trie->getSuggestions(lastWord);
                suggestions.insert(suggestions.end(), fileSuggestions.begin(), fileSuggestions.end());
            }
            for (auto& child : node->children) {
                collectSuggestions(child, prefix, suggestions);
            }
        }

        graphs graph;
        graphs getConnectivityGraph() const {
            static graphs graph; 

            graph.mainlist.clear();

            buildConnectivityGraph(root, graph);

            return graph;
        }

        void buildConnectivityGraph(TreeNode* node, graphs& graph) const {
            if (node->isFile && node->trie) {
                vector<string> words = node->trie->getSuggestions("");
                for (const auto& word : words) {
                    if (word.find(".txt") != string::npos && word != node->name) {
                        graph.insertvertex(node->name);
                        graph.insertvertex(word);
                        graph.insertedge(node->name, word, 0); 
                    }
                }
            }
            for (auto& child : node->children) {
                buildConnectivityGraph(child, graph);
            }
        }

        void printConnectivityGraph(const graphs& graph) const {
            cout << "Connectivity Graph:" << endl;
            for (const auto& vertex : graph.mainlist) {
                cout << "File " << vertex.data << " is connected to:";
                for (const auto& edge : vertex.seclist) {
                    cout << " " << edge.first;
                }
                cout << endl;
            }
        }
    };
}
