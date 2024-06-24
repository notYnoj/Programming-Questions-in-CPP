class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0, flips = 0;
      //ans keeps track of answers
      //flips is hte amount of flips we have done
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] + flips) % 2 == 0) { // if its zero we need to flip
                if(i > nums.size() - k) {
                    return -1;
                  // if we cant flip then its not possible
                } else {
                    ans++;
                    flips++;
                    nums[i] = -1;
                  //set that we flipped at nums[i]
                }
            }
            if(i + 1 >= k) {//if we cna check backwawrds
                flips -= (nums[i - k + 1] < 0);     //check if we flipped on that number if so we need to subtract by 1
              //this is becuz that flip will no longer affect future flips
            }
        }
        return ans;
    }
};
