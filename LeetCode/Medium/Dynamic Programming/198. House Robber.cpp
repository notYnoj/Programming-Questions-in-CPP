class Solution {
public:
//dfs+memo sol:
    int rob(vector<int>& nums) {
        unordered_map<int, int> memo;
        return dfs(memo, 0, nums);
    }
private:
    int dfs(unordered_map<int, int>& memo, int pos, vector<int>& nums){
        //if we go outta bounds
        if (pos >= nums.size()){
            return 0;
        }
      //if in our memo
        if(memo.find(pos)!=memo.end()){
            return memo[pos];
        }
      //take, if we take we must skip a house
        int take = nums[pos]+dfs(memo, pos+2, nums);
      //if not we go to the next house
        int skip = dfs(memo, pos+1, nums);
      //take the max
        int res = max(take, skip);
      //set it equal in our memo
        memo[pos] = res;
        return memo[pos]; //return
    }
};
