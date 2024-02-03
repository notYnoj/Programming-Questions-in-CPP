class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
      //go backwards make sure to do min of k and i to not go outta bounds
        for(int i = 1; i<=n; i++){
            int mx = -1;
            for(int j = 1; j<=min(k,i); j++){
              //take max varaible
                mx = max(mx, arr[i-j]);
              //add the dp[i-j]becuz the rest are gonna become max variable
                dp[i] = max(dp[i], dp[i-j]+mx*j);
            }
        }
        return dp[n];
    }
};
