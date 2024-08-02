class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                c++;
            }
        }
        for(int i = 0; i<c-1; i++){
            nums.push_back(nums[i]);
        }
        int ans = INT_MAX;
        int l = 0; 
        int r = c-1;
        int cur = 0;
        for(int i = 0; i<=r; i++){
            if(nums[i] == 1){
                cur++;
            }
        }
        ans = min(ans, c-cur);
        for(int i = r+1; i<(n+c-1); i++){
            if(nums[l] == 1){
                cur--;
            }
            l++;
            r++;
            if(nums[r] == 1){
                cur++;
            }
            ans = min(ans, c-cur);
        }
        return ans;
    }
};
