class Solution {
public:
    bool closeStrings(string word1, string word2) {
      //idea here is to create two hashmaps and check if they are equal. 
      //if not if one is 0 then its not possible 
      //otherwise we iterate thru the hashmap again and check to see if there is one equal and not solved for yet. 
      //if there is swap.
        vector<int> hsh(26);
        vector<int> hsh2(26);
        if(word1.size() != word2.size()){
            return false;
        }
        for(int i = 0; i<word2.size(); i++){
            hsh2[word2[i]-'a']++;
        }
        for(int i = 0; i<word1.size(); i++){
            hsh[word1[i]-'a']++;
        }
        vector<bool> check(26, false);
        for(int i = 0; i<26; i++){
            if(hsh[i] == hsh2[i]){
                check[i] = true;
                continue;
            }
            if((hsh[i] == 0 && hsh2[i]>0) || (hsh[i]>0 && hsh2[i] == 0)){
                return false;
            }else{
                for(int j = 0; j<26; j++){
                    if(hsh[i] == hsh2[j] && !check[j]){
                        swap(hsh2[i], hsh2[j]);
                        check[i] = true;
                    }
                }
            }
        }
        return hsh == hsh2;
    }
};
