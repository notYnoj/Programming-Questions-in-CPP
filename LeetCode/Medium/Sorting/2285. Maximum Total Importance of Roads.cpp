class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<vector<int>> rds(n);
        for(int i = 0; i<roads.size(); i++){
            auto cur = roads[i];
            rds[cur[0]].push_back(cur[1]);
            rds[cur[1]].push_back(cur[0]);        
        }
        long long ptr = n;
        sort(rds.begin(), rds.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();});

        for(int i = n-1; i>=0; i--){
            ans+=(ptr*(long long)rds[i].size());
            ptr--;
        }
        return ans;

    }
};
