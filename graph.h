#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

struct flist {
    string data;
    list<pair<string, int>> seclist;
};

class graphs {
public:
    list<flist> mainlist;

public:
    void insertvertex(const string& d) {
        // Check if the vertex already exists
        for (const auto& vertex : mainlist) {
            if (vertex.data == d) {
                return; // Vertex already exists, so do not add it again
            }
        }

        // Vertex does not exist, so add it
        flist vertex;
        vertex.data = d;
        mainlist.push_back(vertex);
    }

    void deletevertex(const string& d) {
        typename list<flist>::iterator temp = mainlist.begin();
        while (temp != mainlist.end()) {
            if ((*temp).data == d) {
                temp = mainlist.erase(temp);
            }
            else {
                typename list<pair<string, int>>::iterator innerTemp = (*temp).seclist.begin();
                while (innerTemp != (*temp).seclist.end()) {
                    if ((*innerTemp).first == d) {
                        innerTemp = (*temp).seclist.erase(innerTemp);
                    }
                    else {
                        innerTemp++;
                    }
                }
                temp++;
            }
        }
    }

    void totalvertex() {
        int count = 0;
        typename list<flist>::iterator temp = mainlist.begin();
        while (temp != mainlist.end()) {
            count++;
            temp++;
        }
        cout << "Total Number of Vertex are: " << count << endl;
    }

    void totaledge() {
        int count = 0;
        typename list<flist>::iterator temp = mainlist.begin();
        while (temp != mainlist.end()) {
            count = count + (*temp).seclist.size();
            temp++;
        }
        cout << "Total Number of Edges are: " << count / 2 << endl;
    }

    void insertedge(const string& v1, const string& v2, int w) {
        bool edgeExists = false;
        typename list<flist>::iterator temp = mainlist.begin();

        while (temp != mainlist.end()) {
            if ((*temp).data == v1) {
                typename list<pair<string, int>>::iterator innerTemp = (*temp).seclist.begin();
                while (innerTemp != (*temp).seclist.end()) {
                    if ((*innerTemp).first == v2) {
                        edgeExists = true;
                        break;
                    }
                    innerTemp++;
                }
                if (!edgeExists) {
                    (*temp).seclist.push_back(make_pair(v2, w));
                }
            }
            if ((*temp).data == v2) {
                typename list<pair<string, int>>::iterator innerTemp = (*temp).seclist.begin();
                while (innerTemp != (*temp).seclist.end()) {
                    if ((*innerTemp).first == v1) {
                        edgeExists = true;
                        break;
                    }
                    innerTemp++;
                }
                if (!edgeExists) {
                    (*temp).seclist.push_back(make_pair(v1, w));
                }
            }
            temp++;
        }
    }

    void edgeexist(const string& v1, const string& v2) {
        bool exists = false;
        typename list<flist>::iterator temp = mainlist.begin();
        while (temp != mainlist.end()) {
            if ((*temp).data == v1) {
                typename list<pair<string, int>>::iterator innerTemp = (*temp).seclist.begin();
                while (innerTemp != (*temp).seclist.end()) {
                    if ((*innerTemp).first == v2) {
                        exists = true;
                        break;
                    }
                    innerTemp++;
                }
            }
            temp++;
        }
        if (exists) {
            cout << "Hurrah! Edge exists between " << v1 << " and " << v2 << endl;
        }
        else {
            cout << "Oh! Edge does not exist between " << v1 << " and " << v2 << endl;
        }
    }

    void deleteedge(const string& v1, const string& v2) {
        typename list<flist>::iterator temp = mainlist.begin();
        while (temp != mainlist.end()) {
            if ((*temp).data == v1) {
                typename list<pair<string, int>>::iterator innerTemp = (*temp).seclist.begin();
                while (innerTemp != (*temp).seclist.end()) {
                    if ((*innerTemp).first == v2) {
                        innerTemp = (*temp).seclist.erase(innerTemp);
                        break;
                    }
                    else {
                        innerTemp++;
                    }
                }
            }
            if ((*temp).data == v2) {
                typename list<pair<string, int>>::iterator innerTemp = (*temp).seclist.begin();
                while (innerTemp != (*temp).seclist.end()) {
                    if ((*innerTemp).first == v1) {
                        innerTemp = (*temp).seclist.erase(innerTemp);
                        break;
                    }
                    else {
                        innerTemp++;
                    }
                }
            }
            temp++;
        }
        cout << "Edge between vertex " << v1 << " and " << v2 << " deleted." << endl;
    }

    void vertexsearch(const string& v1) {
        typename list<flist>::iterator temp = mainlist.begin();
        while (temp != mainlist.end()) {
            if ((*temp).data == v1) {
                cout << "Vertex Exists." << endl;
                return;
            }
            temp++;
        }
        cout << "Vertex does not exist." << endl;
    }

    int getnumberofVertices() {
        typename list<flist>::iterator temp = mainlist.begin();
        int count = 0;
        while (temp != mainlist.end()) {
            count++;
            temp++;
        }
        return count;
    }

    void getweight(const string& v1, const string& v2) {
        typename list<flist>::iterator temp = mainlist.begin();
        while (temp != mainlist.end()) {
            if ((*temp).data == v1) {
                typename list<pair<string, int>>::iterator innerTemp = (*temp).seclist.begin();
                while (innerTemp != (*temp).seclist.end()) {
                    if ((*innerTemp).first == v2) {
                        cout << (*innerTemp).second;
                        return;
                    }
                    innerTemp++;
                }
            }
            temp++;
        }
    }

    list<string> getAdjacentVertices(const string& vertex) {
        list<string> adjVertices;
        for (const auto& node : mainlist) {
            if (node.data == vertex) {
                for (const auto& neighbor : node.seclist) {
                    adjVertices.push_back(neighbor.first);
                }
                break;
            }
        }
        return adjVertices;
    }

    string BFS(const string& startVertex, const string& endVertex) {
        unordered_map<string, bool> visited;
        unordered_map<string, string> parent;
        queue<string> q;

        for (const auto& vertex : mainlist) {
            visited[vertex.data] = false;
        }

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            string currentVertex = q.front();
            q.pop();

            if (currentVertex == endVertex) {
                string path = endVertex;
                string node = parent[endVertex];
                while (node != startVertex) {
                    path = node + " > " + path;
                    node = parent[node];
                }
                path = startVertex + " > " + path;
                return path;
            }

            for (const auto& neighbor : getAdjacentVertices(currentVertex)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = currentVertex;
                    q.push(neighbor);
                }
            }
        }

        return "No path exists between " + startVertex + " and " + endVertex;
    }


};
