//Initial Solution: 46 Seconds
class Solution {
public:
    int minSteps(string s, string t) {
        int x = 0;
        vector<int> s1(26);
        vector<int> t1(26);
        for(int i =0; i<s.size(); i++){
            s1[s[i]-'a']++;
            t1[t[i]-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(s1[i]!=t1[i]){
                x+=abs(s1[i]-t1[i]);
            }
        }
        return x/2; //because each one counts as 2 1 change + 1 other change that changes 1 character so divide by 2
    }
};
//Second Solution I liked More, 1 Minute 15 Seconds:
class Solution {
public:
    int minSteps(string s, string t) {
        int x = s.size();
        vector<int> s1(26);
        for(int i =0; i<s.size(); i++){
            s1[s[i]-'a']++;
        }
        for(int i = 0; i<t.size(); i++){
            if(s1[t[i]-'a']>0){
                x--;
                s1[t[i]-'a']--;
            }
        }
 
        return x;
    }
};
