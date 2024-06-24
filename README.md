# Web-Brower-and-local-Search-Engine-in-C-+-+
*Working methodology:* 
For search word function, it basically used Trie to find either that word is present in any file or
not, if word found then it backtrace to get its directory and at the end, it read the complete
content of that file and counts how many times that specific word occurs and display their
directory/URL in order of best URL to worst URL, in short in descending order of occurrence. It
is also capable of searching words with logical operator in format like chair AND table, chair OR
table etc. To implement the functionality of displaying content of any file using its path/URL, we
used external libraries to read the file content and saved it in a string to display on the GUI.
We have implemented GUI using .NET framework form-based application. Besides this, we
have used multiple libraries such as
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <set>
Our code GUI also has the functionality of home, back and forward button.
