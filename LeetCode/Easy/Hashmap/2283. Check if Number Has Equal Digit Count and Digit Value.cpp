class Solution {
public:
    bool digitCount(string num) {
        map<int, int> hsh;
        for(int i = 0; i < num.size(); i++){
            hsh[num[i] - '0']++;
        }
        for(auto i: hsh){
            cout<<i.first<<" "<<i.second<<" ";
        }
        for(int i = 0; i < num.size(); i++){
            if(num[i]-'0' != hsh[i]){ 
                return false;
            }
        }
        return true;
    }
};
