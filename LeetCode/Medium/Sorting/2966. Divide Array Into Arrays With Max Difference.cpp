class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
      //when u sort them they will always be to the next closest neighbors.
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
      //go thru the array in triples and check if the smallest element+k is bigger than or equal to the biggest one (basically a range of values that the biggest one must fall in)
      //if yes then we can make it if not return {} the case where it is not possible
      //(Greedily take)
        for(int i = 1; i<nums.size()-1; i+=3){
            if(nums[i-1]+k>=nums[i+1]){
                cur.push_back(nums[i-1]);
                cur.push_back(nums[i]);
                cur.push_back(nums[i+1]);
                res.push_back(cur);
                cur = {};
            }else{
                return {};
            }
        }
        return res;
    }
};
