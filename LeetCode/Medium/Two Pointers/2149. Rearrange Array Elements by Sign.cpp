class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int d = nums.size();
      //positve pointer
        int p = 0;
      //negative pointer
        int n = 1;
        vector<int> output(d);
        for(int i = 0; i<d ;i++){
            if(nums[i]>0){
                output[p] = nums[i];
              //account for the negative
                p+=2;
            }else{
                output[n] = nums[i];
              // and vice versa
                n+=2;
            }
        }
        return output;
    }
};
