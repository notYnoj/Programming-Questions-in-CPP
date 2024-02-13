class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string i: words){
            if(check(i)){
                return i;
            }
        }
        return "";
    }
//check if palindrome
private:
    bool check(string s){
        int i = 0;
        int j = s.size()-1;
        while(j>i){
            if(s[j] == s[i]){
                j--;
                i++;
            }else{
                return false;
            }
        }
        return true;
    }
};
