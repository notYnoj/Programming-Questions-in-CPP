class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hsh;
        vector<int> res;
        for(int i = 0; i<nums.size(); i++){
            int z = target - nums[i];
            if(hsh.find(z) != hsh.end()){
                res = {i, hsh[z]};
                return res;
            }else{
                hsh[nums[i]] = i;
            }
        }
        return res;
    }
};
