class Solution {
public:
        int solve(int ind, vector<vector<int>>& books, int width, vector<int>& dp) {
        int n = books.size();
        
        if (ind >= n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int maxy = 0, w = 0, ans = INT_MAX;
        for (int i = ind; i < n; ++i) {
            if (w + books[i][0] > width)
                break;
            w += books[i][0];
            maxy = max(maxy, books[i][1]);
            ans = min(ans, maxy + solve(i + 1, books, width, dp));
        }
        
        dp[ind] = ans;
        return dp[ind];
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, -1);
        return solve(0, books, shelfWidth, dp);
    }
};
