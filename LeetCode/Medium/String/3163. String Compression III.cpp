class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i = 0; 
        int n = word.size();
        vector<char> s;
        while(i<n){
            s.push_back(word[i++]);
            assert(!s.empty());
            while(i<n && word[i] == s.back() && s.size()<9){
                s.push_back(word[i++]);
            }

            ans+=to_string(s.size());
            cout<<s.size()<<endl;
            ans+=s.back();
            
            s = {};
        }
        return ans;
    }
};
