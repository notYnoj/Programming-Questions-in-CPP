class Solution {
    const int mxN = 1e9;
    vector<bool> vis; // declare the vector

private:
    vector<pair<int, int>> moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void bfs(int x, int y, vector<vector<int>>& grid2, int n, int m, vector<pair<int, int>>& cur) {
        if(grid2[x][y] == 1) {
            cur.push_back({x, y});
            vis[x*m+y] = true;
        } else {
            return;
        }
        for(int i = 0; i < 4; i++) {
            int dx = moves[i].first;
            int dy = moves[i].second;
            if(x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && !vis[(x+dx)*m+y+dy]) {
                bfs(x + dx, y + dy, grid2, n, m, cur);
            }
        }
    }

public:
    Solution() : vis(mxN, false) {} // initialize the vector in the constructor

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vector<pair<int, int>> check;
                if(!vis[i * m + j] && grid2[i][j] == 1) {
                    bfs(i, j, grid2, n, m, check);
                
                bool good = true;
                for(int i = 0; i < check.size(); i++) {
                    if(grid1[check[i].first][check[i].second] == 0) {
                        good = false;
                        break;
                    }
                }
                if(good) {
                    ans++;
                }
            }

            }
        }
        return ans;
    }
};
