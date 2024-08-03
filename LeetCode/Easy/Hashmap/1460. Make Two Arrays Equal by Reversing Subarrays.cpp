class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> mp(1005), mp2(1005 );
        if(target.size() != arr.size()){
            return false;
        }
        for(int i = 0; i<target.size(); i++){
            mp[target[i]]++;
            mp2[arr[i]]++;
        }
        for(int i = 0; i<1005; i++){
            if(mp[i] != mp2[i]) return false;
        }
        return true;
    }
};
