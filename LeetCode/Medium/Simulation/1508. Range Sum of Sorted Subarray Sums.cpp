class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9+7;
        int ans = 0;
        vector<int> sum;
        for(int i = 0; i<n; i++){
            int cur = 0;
            for(int j = i; j>=0; j--){
                cur+=nums[j];
                sum.push_back(cur);
            }
        }
        sort(sum.begin(), sum.end());
        for(int i = left-1; i<right; i++){
            ans+=sum[i];
            ans%=mod;
        }
        return ans;
    }
};
