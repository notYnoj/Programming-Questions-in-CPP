class Solution {
public:
    int missingNumber(vector<int>& nums) {
      //check against what it supposed to be
        sort(nums.begin(), nums.end());
        if(nums[0] != 0){
            return 0;
        }
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]!=nums[i-1]+1){
                return i;
            }
        }
        return nums.size();
    }
};
