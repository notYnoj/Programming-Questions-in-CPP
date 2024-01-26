class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        unordered_map<long long, int> memo;
`        //simple dfs where base case is outside or moves == 0, or if in memo then we js go in the 4 cardinal directions and add the paths we get from there
        return dfs(startRow, startColumn, maxMove, m, n, memo) % MOD;
    }

private:
    int dfs(int row, int col, int move, int m, int n, unordered_map<long long, int>& memo) {
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        }
        if (move == 0) {
            return 0;
        }

        long long key = ((long long)row * 100 + col) * 100 + move;

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int paths = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (const auto& dir : directions) {
            int new_row = row + dir.first;
            int new_col = col + dir.second;
            paths = (paths + dfs(new_row, new_col, move - 1, m, n, memo)) % 1000000007;
        }

        memo[key] = paths;
        return paths;
    }
};
