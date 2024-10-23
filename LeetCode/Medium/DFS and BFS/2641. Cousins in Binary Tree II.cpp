/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root) {
        if(!root)return;

        queue<pair<int,pair<TreeNode*,int>>> q, q2;
        vector<int> levSum;
        int level=0;
        q.push({level,{root,root->val}});

        while(!q.empty()){
            int n=q.size();
            int levelSum=0;
            while(n--) {
                TreeNode* top=q.front().second.first;
                q.pop();
                int sibSum=0;
                if(top->left){
                    sibSum+=top->left->val;
                    levelSum+=top->left->val;
                }
                if(top->right){
                    sibSum+=top->right->val;
                    levelSum+=top->right->val;
                }
                if(top->left){
                    q.push({level,{top->left, sibSum}});
                    q2.push({level,{top->left, sibSum}});
                }
                if(top->right){
                    q.push({level,{top->right, sibSum}});
                    q2.push({level,{top->right, sibSum}});
                }
            }
            levSum.push_back(levelSum);
            level++;
        }
        while(!q2.empty()) {
            TreeNode* top = q2.front().second.first;
            int lvl = q2.front().first;
            int sibsum = q2.front().second.second;

            top->val = levSum[lvl]-sibsum;
            q2.pop();
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        bfs(root);
        root->val=0;
        return root;
    }
};
