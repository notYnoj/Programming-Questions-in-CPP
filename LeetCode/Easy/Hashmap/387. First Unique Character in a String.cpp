class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hsh(26,0);
        map<char, int> mp;
        for(int i = 0; i<s.size(); i++){
            hsh[s[i]-'a']++;
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = i;
            }
        }
      //js use two hashmaps, one for occurence and one for keeping track of the initial pos
        int m = 1e5+1;
        for(int i = 0; i<26; i++){
            if(hsh[i] == 1){
                m = min(mp[i+'a'], m);
            }
        }
        return m<1e5+1?m:-1;
    }
};
