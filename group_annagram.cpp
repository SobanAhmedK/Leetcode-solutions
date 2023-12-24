#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const auto& str : strs) {
    
        string key = str;
        sort(key.begin(), key.end());

        
        anagramGroups[key].push_back(str);
    }
    vector<vector<string>> result;
    for (const auto& group : anagramGroups) {
        result.push_back(group.second);
    }

    return result;
}

int main() {
    // Example usage
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Call the function to group anagrams
    vector<vector<string>> result = groupAnagrams(input);

    // Display the result
    for (const auto& group : result) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
