class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(int i: nums1){
            s.insert(i);
        }
        sort(nums2.begin(), nums2.end());
        for(int i: nums2){
            if(s.find(i) != s.end()){
                return i;
            }
        }
        return -1;
    }
};
//not optimal but easy.
