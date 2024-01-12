class Solution {
public:
    bool halvesAreAlike(string s) {
        int x = 0;
        int y = 0;
        int m = s.size()/2;
        map<char, int> mp = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4},{'A', 5}, {'E', 6}, {'I', 7}, {'O', 8}, {'U', 9}};        
        for(int i = 0; i<m; i++){
            if(mp.find(s[i])!=mp.end()){
                x++;
            }
        }
        for(int i = m; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end()){
                y++;
            }
        }   
        if(x!=y){
            return false;
        }
        return true;
    }
};

/*
Note: My original Wrong Answer, please read the question fully ._. 
class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<int> hsh1(10);
        vector<int> hsh2(10);
        int m = s.size()/2;
        map<char, int> mp = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4},{'A', 5}, {'E', 6}, {'I', 7}, {'O', 8}, {'U', 9}};        
        for(int i = 0; i<m; i++){
            if(mp.find(s[i])!=mp.end()){
                hsh1[mp[s[i]]]++;
            }
        }
        for(int i = m; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end()){
                hsh2[mp[s[i]]]++;
            }
        }   
        for(int i = 0; i<10; i++){
            if(hsh1[i]!=hsh2[i]){
                return false;
            }
        }
        return true;
    }
};
*/
