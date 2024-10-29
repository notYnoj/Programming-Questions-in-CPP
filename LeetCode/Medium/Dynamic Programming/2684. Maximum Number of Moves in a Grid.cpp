class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int ans = 0;

        // Start with all cells in the first column
        for (int i = 0; i < rows; i++) {
            dp[i][0] = 1;
        }

        // Iterate through the grid, row by row
        for (int j = 0; j < cols - 1; j++) {
            for (int i = 0; i < rows; i++) {
                if (dp[i][j] > 0) { // Only proceed if cell has been reached
                    // Move down-right
                    if (i > 0 && grid[i-1][j+1] > grid[i][j]) {
                        dp[i-1][j+1] = max(dp[i-1][j+1], dp[i][j] + 1);
                        ans = max(ans, dp[i-1][j+1]);
                    }
                    // Move right
                    if (grid[i][j+1] > grid[i][j]) {
                        dp[i][j+1] = max(dp[i][j+1], dp[i][j] + 1);
                        ans = max(ans, dp[i][j+1]);
                    }
                    // Move up-right
                    if (i < rows - 1 && grid[i+1][j+1] > grid[i][j]) {
                        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
                        ans = max(ans, dp[i+1][j+1]);
                    }
                }
            }
        }
        return max(0,ans - 1); // Subtract 1 because the initial move count was set to 1
    }
};
