class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        unordered_map<string, int> memo;
        return dfs(0, 0, cols - 1, grid, memo);
    }

private:
    int dfs(int row, int col1, int col2, vector<vector<int>>& grid, unordered_map<string, int>& memo) {
        if (row == grid.size()) {
            return 0;
        }

        string key = to_string(row) + "_" + to_string(col1) + "_" + to_string(col2);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int cherries = grid[row][col1] + (col1 != col2 ? grid[row][col2] : 0);

        int maxCherries = 0;
        for (int move1 = -1; move1 <= 1; ++move1) {
            for (int move2 = -1; move2 <= 1; ++move2) {
                int newCol1 = col1 + move1;
                int newCol2 = col2 + move2;

                if (newCol1 >= 0 && newCol1 < grid[0].size() && newCol2 >= 0 && newCol2 < grid[0].size()) {
                    maxCherries = max(maxCherries, cherries + dfs(row + 1, newCol1, newCol2, grid, memo));
                }
            }
        }

        memo[key] = maxCherries;

        return maxCherries;
    }
};
