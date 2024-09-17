class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        set<string> s;
        vector<string> to_erase;
        int n= s1.size();
        int m = s2.size();
        string cur = "";

        for(int i = 0; i<n; i++){
            if(s1[i] == ' '){
                if(s.count(cur)){
                    to_erase.push_back(cur);
                }else{
                    s.insert(cur);
                }
                cur = "";
            }else{
                cur+=s1[i];
            }
        }
        if(s.count(cur) && cur != " "){
            to_erase.push_back(cur);
        }else{
            s.insert(cur);
        }
        cur = "";
        for(int i = 0; i<m; i++){
            if(s2[i] == ' '){
                if(s.count(cur)){
                    to_erase.push_back(cur);
                }else{
                    s.insert(cur);
                }
                cur = "";
            }else{
                cur+=s2[i];
            }
        }
        if(s.count(cur) && cur != " "){
            to_erase.push_back(cur);
        }else{
            if(cur != " "){
                s.insert(cur);
            }
        }
        for(auto i: to_erase){
            s.erase(i);
        }
        vector<string> ans;
        for(auto i: s){
            ans.push_back(i);
        }
        return ans;
        
    }
};
