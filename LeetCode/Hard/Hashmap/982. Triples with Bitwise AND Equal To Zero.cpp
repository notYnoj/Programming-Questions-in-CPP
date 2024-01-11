class Solution {
public:
    int countTriplets(vector<int>& nums) {
        //bruh js brute force it but use a hashmap O(N^2) TC
        unordered_map<int,int> mp;
        for(int i: nums){
            for(int j: nums){
                mp[i&j]++;
            }
        }
        int ans = 0;
        for(int i: nums){
            for(auto j: mp){
                if((i&j.first)==0){
                  ans += j.second;
                }
            }
        }
        return ans;
    }
};
