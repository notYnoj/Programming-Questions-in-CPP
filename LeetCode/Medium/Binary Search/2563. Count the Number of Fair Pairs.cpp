class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long pairs = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            int cur = nums[i];
            int b = upper_bound(nums.begin()+i+1, nums.end(), upper-cur)-nums.begin();
            int c = lower_bound(nums.begin()+i+1, nums.end(), lower-cur)-nums.begin();
            if(c<b){
                pairs+=b-c;
            }
        }
        return pairs;
    }
};
