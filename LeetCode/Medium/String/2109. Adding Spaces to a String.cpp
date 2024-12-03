class Solution {
public:
    string addSpaces(string s, vector<int>& pl) {
        string result;
        int posIndex = 0, n = s.size(), m = pl.size();

        for (int i = 0; i < n; ++i) {
            // Check if current index matches a position in `pl`
            if (posIndex < m && i == pl[posIndex]) {
                result += ' ';
                ++posIndex;
            }
            result += s[i];
        }

        return result;
    }
};
