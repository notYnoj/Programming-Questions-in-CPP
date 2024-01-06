class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distances(n, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;
        // all land cells and their distance is 0 cuz a land cell = land cell also make sure there are land cells
        bool done = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    distances[i][j] = 0;
                    done = true;
                }
            }
        }
        if(!done){
            return -1;
        }

        // da bfs 
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // go thru ykyk
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                // if its valid and the next one is NOT a land cell add 1 distance
                if (isValid(nx, ny, n) && distances[nx][ny] == INT_MAX) {
                    distances[nx][ny] = distances[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int maxDistance = -1;

        // maximum distance among water cells
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && distances[i][j] != INT_MAX) {
                    maxDistance = max(maxDistance, distances[i][j]);
                }
            }
        }

        return maxDistance == -1 ? -1 : maxDistance;
    }

private:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    bool isValid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
};
