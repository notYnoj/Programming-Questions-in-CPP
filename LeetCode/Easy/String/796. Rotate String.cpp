class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n != goal.size()){
            return false;
        }
        for(int i = 0; i<=n; i++){
            string cur = s.substr(i);
            if(cur ==goal){
                return true;
            }
            s+=s[i];
        }
        return false;
    }
};
