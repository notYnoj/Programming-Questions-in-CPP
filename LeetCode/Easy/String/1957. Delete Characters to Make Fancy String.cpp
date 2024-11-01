class Solution {
public:
    string makeFancyString(string s) {
        int l = 0;
        string ans = "";
        int n = s.size();
        for(int i = 1; i<s.size(); i++){
            if(s[i] != s[i-1]){
                ans+=string( min(i-l, 2),s[i-1]);
                l = i;
            }
        }
        ans+=string(min(n-l, 2),s[s.size()-1]);
        return ans;
        
    }
};
