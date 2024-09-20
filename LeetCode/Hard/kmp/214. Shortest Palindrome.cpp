class Solution {
public:
    string shortestPalindrome(string s) {
        string modified = s + "_" + string(s.rbegin(), s.rend());
        vector<int> kmpTable(modified.length(), 0);
        for (int i = 1, j = 0; i < modified.length(); ) {
            if (modified[i] == modified[j]) {
                kmpTable[i++] = ++j;
            } else {
                if (j > 0) {
                    j = kmpTable[j - 1];
                } else {
                    kmpTable[i++] = 0;
                }
            }
        }
        int len = kmpTable.back();
        return string(s.rbegin(), s.rbegin() + s.length() - len) + s;
    }
};
