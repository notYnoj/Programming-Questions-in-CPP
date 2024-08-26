/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == nullptr){
            return {};
        }
        stack<Node*> s;
        map<Node*, bool> used;
        s.push(root);
        vector<int> ans;
        while(!s.empty()){
            Node* cur = s.top();
            bool can = true;
            vector<Node*> child = cur->children;
            for(auto i: child){
                cout<<i->val<<' ';
                if(i == nullptr){
                    continue;
                }
                can = can&used[i];
            }
            if(can){
                ans.push_back(cur->val);
                used[cur] = true;
                s.pop();
            }else{
                reverse(child.begin(), child.end());
                for(auto i: child){
                    s.push(i);
                }
            }
        }
        return ans;
    }
};
