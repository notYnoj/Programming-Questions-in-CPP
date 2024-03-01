//if odd return if even add 1 then return
class Solution {
public:
    string generateTheString(int n) {
        if(n%2 == 1){
            string s ="";
            while(n--){
                s+='a';
            }
            return s;
        }else{
            string s = "";
            n--;
            s+='a';
            cout<<n;
            while(n--){
                s+='b';
                
            }
            return s;
        }
        return "";
    }
};
