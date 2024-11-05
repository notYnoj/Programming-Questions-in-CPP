class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int ans = 0;
        bool tr = (s[0] == '1'?true:false);
        for(int i = 1, count = 1; i<n; i++){
            if(s[i] == '1' && !tr){
                if(count%2){
                    ans++;
                    count = 0;
                    tr = !tr;
                }else{
                    count = 1;
                    tr = !tr;
                }
            }else if(s[i] == '0' && tr){
                if(count%2){
                    ans++;
                    count = 0;
                    tr = !tr;
                }else{
                    count = 1;
                    tr = !tr;
                }
            }else{
                count++;
            }
        }
        return ans;
    }
};
