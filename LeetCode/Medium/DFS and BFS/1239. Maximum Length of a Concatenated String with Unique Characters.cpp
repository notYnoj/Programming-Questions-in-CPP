class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        dfs(arr, "", 0, result);
        return result;
    }

private:
    void dfs(const vector<string>& arr, string current, int index, int& result) {
        if (hasUniqueCharacters(current)) {
            result = max(result, static_cast<int>(current.length())); //static cast is needed because .length() doesnt return an int, so max cant be used
        } else {
            return;
        }

        for (int i = index; i < arr.size(); ++i) {
            dfs(arr, current + arr[i], i + 1, result); // append all to current s and if it works update otherwise break out of the current s, becuz yk it wont work
        }
    }

    bool hasUniqueCharacters(const string& s) { //check
        unordered_set<char> charSet;
        for (char c : s) {
            if (charSet.count(c) > 0) {
                return false;
            }
            charSet.insert(c);
        }
        return true;
    }
};
