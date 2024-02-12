class Solution {
public:
    int majorityElement(vector<int>& nums) {
      //hashmap to store all elements
        int n = nums.size();
        map<int, int> mp;
        int needed = n/2;
        for(int i : nums){
            mp[i]++;
        }
        for(auto i: mp){
            if(i.second>needed){
                return i.first;
            }
        }
        return -1;
    }
};
