class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<bool> bad(1002, false);
        for(int i =0; i<nums.size(); i++){
            if(nums[i]%original == 0){
                int t = nums[i]/original;
                int tz = log2(t);
                cout<<tz;
                if(pow(2, tz) == t){
                    bad[tz] = true;
                }
            }
        }
        if(!bad[0]){
            return original;
        }
        for(int i = 1; i<=1000; i++){
            if(!bad[i]){
                return original * (1<<i); 
            }
        }
        return -1;
    }
};
