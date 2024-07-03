class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums.size() == 5){
            int a = 999999;
            for(int i =0; i<n-1; i++){
                a = min(a, nums[i+1]-nums[i]);
            }
            return a;
        }
        if(nums.size()<=4){
            return 0;
        }else{
            int l = 0;
            int r= n-1;
            for(int i = 0; i<3; i++){
                if((nums[r] -nums[r-(3-i)])>(nums[l+(3-i)]-nums[l])){
                    r--;
                }else{
                    l++;
                }
            }
            int ans = (nums[r]-nums[l]);
            return ans;
        }

    }
};
