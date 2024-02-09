class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
      //basically js use dp to find the max subset at each i,
      //store what we used in the prev_index to make
      //then go back from there 
        int n = nums.size();
        vector<int> dp(n+1, 1);
        vector<int> prev_index(n+1, -1);
        int max_length = 1;
        int max_index = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev_index[i] = j;
                    if(dp[i] > max_length) {
                        max_length = dp[i];
                        max_index = i;
                    }
                }
            }
        }
    
        vector<int> subset;
        while(max_index != -1) {
            subset.push_back(nums[max_index]);
            max_index = prev_index[max_index];
        }
    
        reverse(subset.begin(), subset.end());
    
        return subset;
    }
};
