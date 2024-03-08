class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> hsh(101, 0);
        for(int i: nums){
            hsh[i]++;
        }
        sort(hsh.begin(), hsh.end());
        int score = hsh[100];
        int looking = hsh[100];
        for(int i = 99; i>=0; i--){
            if(hsh[i] == looking){
                score+=hsh[i];
            }else{
                break;
            }
        }
        return score;
    }
};
