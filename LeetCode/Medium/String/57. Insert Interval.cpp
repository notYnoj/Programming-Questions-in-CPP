//super annoying LMAO
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()){
            return {newInterval};
        }
        vector<vector<int>> ans;
        int a = newInterval[0];
        int b = newInterval[1];
        int n = intervals.size();
        bool insert = false;
        int i = 0;
        while(i<n){
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(l<=b&&a<=r && !insert){
                l = min(a,l);
                while(i<n-1 && b>=intervals[i+1][0]){
                    i++;
                }

                r = max(b, intervals[i][1]);

                ans.push_back({l,r});
                insert= true;
            }else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        if(!insert){
            ans.push_back(newInterval);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
