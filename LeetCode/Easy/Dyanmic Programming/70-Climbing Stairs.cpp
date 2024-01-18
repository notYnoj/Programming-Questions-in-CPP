class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(46);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i<=n; i++){
          //add the ways to get +1, and +2
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
};
