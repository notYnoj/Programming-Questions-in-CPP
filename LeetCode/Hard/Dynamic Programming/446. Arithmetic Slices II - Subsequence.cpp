class Solution {
public:   
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count = 0; 
        // dp[i][j] represents the number of arithmetic subsequences ending at index i with difference j
        vector<unordered_map<long long, int>> dp(n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j];
                int dp_i_j = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += dp_i_j + 1;
                count += dp_i_j;
            }
        }
    return count;
    }
};
