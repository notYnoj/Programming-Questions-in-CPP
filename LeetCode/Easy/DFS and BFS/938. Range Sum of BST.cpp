//Pretty Simple BST, simply check and it works, O(N) TC (searching all nodes)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int amnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(low<=node->val && high>=node->val){
                amnt+=node->val;
            }
            if(node -> left){
                q.push(node->left);

            }
            if(node->right){
                q.push(node->right);
            }
        }
        return amnt;
    }
};
