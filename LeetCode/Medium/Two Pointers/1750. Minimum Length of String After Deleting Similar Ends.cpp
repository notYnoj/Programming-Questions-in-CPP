class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(s[l] == s[r]){
                while(s[l] == s[l+1] && l<r){
                    l++;
                }
                while(s[r] == s[r-1] && l<r){
                    r--;
                }
                l++;
                r--;
            }else{
                break;
            } 
        }
       
        return l>r? 0 : r-l+1;
    }
};
