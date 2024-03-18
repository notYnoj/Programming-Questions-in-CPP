class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
      //we want to take the leftest most then if theres a balloon that doesnt get hit by it we need an another dart we keep doing this, we sort by last one because we know this one will not get hit ykyk
        int ans = 0;
        int i = 0;
        int n = points.size();
        while(i<n){
            if(i<n-1&&points[i][1]>=points[i+1][0]){
                int l = min(points[i][1],points[i+1][1]);
                i++;
                while(i<n && l>=points[i][0]){
                    i++;
                }
                ans++;
            }else{
                ans++;
                i++;
            }
        }
        return ans;
    }
};
