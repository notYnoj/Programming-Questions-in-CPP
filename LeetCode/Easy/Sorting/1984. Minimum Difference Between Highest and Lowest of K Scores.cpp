class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        if(k == nums.size()){
            return nums[nums.size()-1]-nums[0];
        }
        for(int i = 0; i<=nums.size()-k; i++){
            ans = min(nums[i+k-1]-nums[i], ans);
        }
        return ans;
    }
};
