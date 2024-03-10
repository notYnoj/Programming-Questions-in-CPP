class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> has(1001);
        for(int i: nums1){
            has[i] = true;
        }
        vector<bool> used(1001, false);
        vector<int> ans;
        for(int i: nums2){
            if(has[i] && !used[i]){
                ans.push_back(i);
                used[i] = true;
            }
        }
        return ans;
    }
};
