class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n); //hashmap that will count the occurence of each number from 1-n
        for(int i = 0; i<n ;i++){
            arr[nums[i]-1]++;
        }
        vector<int> ans(2); //ordering matters in this question
        for(int i = 0; i<n; i++){
            if(arr[i]==2){
                ans[0] = i+1; // ordering matters
            }else if(arr[i] == 0){
                ans[1] = i+1; //ordering matters
            }
        }
        return ans;
    }
};
