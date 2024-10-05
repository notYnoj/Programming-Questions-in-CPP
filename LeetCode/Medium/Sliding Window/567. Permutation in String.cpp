class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       unordered_map<char,int> s1_dict,temp;
       for(int i=0;i<s1.size();i++){
           s1_dict[s1[i]]++;
       }
       for(int i=0;i<s2.size();i++){
           if(s1_dict.find(s2[i]) != s1_dict.end()){ 
        temp = s1_dict ;
        int count = 0;
        int j = i;
        while(j<s2.size() &&temp.find(s2[j]) != temp.end() ){
            temp[s2[j]]--;
            count++;
            if(temp[s2[j]] == 0){
                temp.erase(s2[j]);
            }
            j++;
        }
        if(s1_dict.find(s2[j]) == s1_dict.end()){
          i = j;  
        }
        
        if(count == s1.size()) return true;
        }
        
        }
    return false;
    }
};
