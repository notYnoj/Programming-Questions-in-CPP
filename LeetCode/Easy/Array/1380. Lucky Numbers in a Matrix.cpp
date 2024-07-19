class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int, int>> rows(n, {INT_MAX, 0});
        vector<pair<int, int>> cols(m, {INT_MIN, 0});
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                auto row = rows[i];
                auto col = cols[j];
                int cur = matrix[i][j];
                if(cur<row.first){
                    rows[i] = {cur, j};
                }
                if(cur>col.first){
                    cols[j] = {cur, j};
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i<n; i++){
            auto cur  = rows[i];
            if(cur.first == cols[cur.second].first){
                ans.push_back(cur.first);
            }
        }
        return ans;
        
    }
};
