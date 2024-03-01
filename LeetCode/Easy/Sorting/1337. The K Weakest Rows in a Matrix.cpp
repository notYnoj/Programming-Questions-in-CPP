class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> t;
        for(int i = 0; i<m; i++){
            t.push_back({0,i});
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j]){
                    t[i].first += 1;
                }
            }
        }
        sort(t.begin(), t.end());
        vector<int> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(t[i].second);
        }
        return ans;

    }
};
//use pq
/*
Code Sample (Runtime: 0ms)

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
         for(int i=0;i<mat.size();i++){
             int count=0;
             for(int j=0;j<mat[i].size();j++){
                 if(mat[i][j]==1)count++;
             }
             pq.push({count,i});
         }
         vector<int>ans;
         while(k>0){
             ans.push_back(pq.top().second);
             pq.pop();
             k--;
         }
        return ans;
    }
};
*/
