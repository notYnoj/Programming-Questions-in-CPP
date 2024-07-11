class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur = "";
        
        for (char c : s) {
            if (c == '(') {
                st.push(cur);
                cur = "";
            } else if (c == ')') {
                reverse(cur.begin(), cur.end());
                if (!st.empty()) {
                    cur = st.top() + cur;
                    st.pop();
                }
            } else {
                cur += c;
            }
        }
        
        return cur;
    }
};
