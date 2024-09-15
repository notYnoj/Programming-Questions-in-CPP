class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        int mask = 0, maxLength = 0;
        vector<int> pos(32, -1);  // 32 possible states (2^5 for vowels a, e, i, o, u)
        pos[0] = 0;  // Base case: when mask is 0, it means all vowels are even
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') mask ^= (1 << 0);
            if (s[i] == 'e') mask ^= (1 << 1);
            if (s[i] == 'i') mask ^= (1 << 2);
            if (s[i] == 'o') mask ^= (1 << 3);
            if (s[i] == 'u') mask ^= (1 << 4);
            if (pos[mask] != -1) {
                maxLength = max(maxLength, i + 1 - pos[mask]);
            } else {
                pos[mask] = i + 1;
            }
        }
        return maxLength;
    }
};
