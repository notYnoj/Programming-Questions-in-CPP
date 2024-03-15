class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int t = 1;
        for(int i = 0; i<n; i++){
            ans[i] = t;
            t*=nums[i];
        }
        t = 1;
        for(int i = n-1; i>-1; i--){
            ans[i]*=t;
            t*=nums[i];
        }
        return ans;

    }
};
// alot of boring leetcode questions
/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int t = 1;
        int z = 0;
        int f = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                z++;
                if(z ==1){
                    f = i;
                }
            }else{
                t*=nums[i];
            }
        }
        if(z>1){
            vector<int> spec(n, 0);
            return spec;
        }else if(z==1){
            vector<int> spec1(n, 0);
            spec1[f] = t;
            return spec1;
        }else{
            for(int i = 0; i<n ;i++){
                ans[i] = t/nums[i];
            }
            return ans;
        }

    }
};*/

og sol
