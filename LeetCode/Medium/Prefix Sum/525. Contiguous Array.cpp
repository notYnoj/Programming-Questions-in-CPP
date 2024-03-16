class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> a(nums.size(), 0);
        int ans = 0;
        nums[0] == 1? a[0] =1: a[0] =-1;
        map<int, int> hsh;
        hsh[a[0]] = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == 1){
                a[i] = a[i-1]+1;
            }else{
                a[i] = a[i-1]-1;
            }
            if(a[i] == 0){
                ans = max(i+1, ans);
            }else{
                if(hsh.find(a[i]) == hsh.end()){
                    hsh[a[i]] = i;
                }else{
                    ans = max(i-hsh[a[i]], ans);
                }
            }
        }
        return ans;
    }
};
