class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        vector<vector<string>> result;

        for (const string& s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());

            anagramMap[sortedStr].push_back(s);
        }

        for (const auto& entry : anagramMap) {
            result.push_back(entry.second);
        }

        return result;
    }
};
