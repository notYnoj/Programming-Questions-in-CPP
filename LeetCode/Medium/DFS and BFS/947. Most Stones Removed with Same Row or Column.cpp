class Solution {
    vector<bool> vis;

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vis.resize(n, false); 

        int numOfComponents = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, stones);
                numOfComponents++;
            }
        }

        return n - numOfComponents;
    }

    void dfs(int node, vector<vector<int>>& stones) {
        vis[node] = true;
        for (int i = 0; i < stones.size(); ++i) {
            if (!vis[i] && (stones[node][0] == stones[i][0] || stones[node][1] == stones[i][1])) {
                dfs(i, stones);
            }
        }
    }
};
