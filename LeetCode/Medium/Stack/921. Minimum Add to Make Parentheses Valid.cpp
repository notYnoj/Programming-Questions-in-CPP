class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> st;
        for(char i: s){
            if(i == '('){
                st.push_back('(');
            }else{
                if(st.size()>0 && st.back() == '('){
                    st.pop_back();
                }else{
                    st.push_back(')');
                }
            }
        }
        return st.size();
    }
};
