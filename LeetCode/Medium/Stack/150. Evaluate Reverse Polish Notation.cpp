class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        unordered_map<string, int> h = {{"+", 0}, {"-", 1}, {"*", 2}, {"/", 3}};
        for(int i = 0; i<tokens.size(); i++){
            if(h.find(tokens[i]) == h.end()){
                s.push(stoi(tokens[i]));
            }else{
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int c = 0;
                if(h[tokens[i]] == 0){
                    c = a+b;
                    s.push(c);
                }else if(h[tokens[i]] == 1){
                    c = a-b;
                    s.push(c);
                }else if(h[tokens[i]] == 2){
                    c = a*b;
                    s.push(c);
                }else{
                    c = a/b;
                    s.push(c);
                }
            }
            cout<<s.top()<<" ";
        }
        return s.top();
    }
};
