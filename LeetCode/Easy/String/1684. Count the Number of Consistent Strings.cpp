class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> alp(26, false);
        for(char i: allowed) alp[i-'a'] = true;
        int tr = 0;
        for(string i: words){
            bool good = false;
            for(char c: i){
                if(!alp[c-'a']){
                    good = true;
                    break;
                }
            }
            if(!good) tr++;
        }

        return tr;
    }
};
