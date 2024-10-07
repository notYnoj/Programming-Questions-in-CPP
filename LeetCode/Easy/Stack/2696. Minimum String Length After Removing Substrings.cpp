class Solution {
public:
    int minLength(string s) {
        vector<char> st;
        for(char i: s){
            if(st.empty()){
                st.push_back(i);
                continue;
            }
            if((st.back() == 'A' && i == 'B') ||(st.back() == 'C' && i == 'D')){
                st.pop_back();
            }else{
                st.push_back(i);    
            }
        }
        return st.size();
    }
};
