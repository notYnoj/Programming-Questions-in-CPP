class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0; 
        int r = l;
        int n = nums.size();
        int cur = (nums[0]%2);
        while(r<n){
            if(cur == k){
                int left = 1; //represents current subarray (aka including no evens left)
                int right = 1;// represents current subarray (aka including no evens right)
                r++;
                if(r<n)cur+= (nums[r]%2);
                while(r<n&&cur == k){
                    right++;
                    r++;
                    cur+=(nums[r]%2); //go until we cant go anymrore
                }
                while(l<=r&&(nums[l]%2 == 0)){ // we know we are going to have one more so when we reach that one more we found how many lefts of the needed 1
                    left++;
                    l++;
                }
                l++; //make sure we are not in the way of the new one
                cur-=1;
                ans+=(left*right);
            }else{
                r++;
                cur+= (nums[r]%2);
            }
        }
        cout<<l<<" "<<r;
        return ans;
        
    }
};
