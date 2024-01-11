//basically make a vector with all the leaf nodes, apply a dfs to get each leaf node going from left to right
//do this for both trees. then check if the vectors are equal if so true if not false.
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        stack<TreeNode*> s;
        s.push(root1);
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            if(!cur->left && !cur->right){
                tree1.push_back(cur->val);
            }
            if(cur->left){
                s.push(cur->left);
            }
            if(cur->right){
                s.push(cur->right);
            }
        }
        s.push(root2);
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            if(!cur->left && !cur->right){
                tree2.push_back(cur->val);
            }
            if(cur->left){
                s.push(cur->left);
            }
            if(cur->right){
                s.push(cur->right);
            }
        }
        if(tree1.size()!=tree2.size()){
            return false;
        }
        for(int i = 0; i<tree1.size(); i++){
            if(tree1[i] != tree2[i]){
                return false;
            }
        }
        return true;
    }
};
