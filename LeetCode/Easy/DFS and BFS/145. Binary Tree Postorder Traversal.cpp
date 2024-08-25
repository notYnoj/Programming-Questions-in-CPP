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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {}; 

        stack<TreeNode*> s;
        vector<int> ans;
        s.push(root);
        map<TreeNode*, bool> used; // Use TreeNode* as the key

        while (!s.empty()) {
            TreeNode* cur = s.top();
            
            // If both children are null or already visited, process the current node
            if ((cur->left == nullptr || used[cur->left]) && (cur->right == nullptr || used[cur->right])) {
                ans.push_back(cur->val);
                used[cur] = true; // Mark current node as visited
                s.pop();
            } else {
                // Push right and left children to stack (right first to process left first)
                if (cur->right != nullptr && !used[cur->right]) {
                    s.push(cur->right);
                }
                if (cur->left != nullptr && !used[cur->left]) {
                    s.push(cur->left);
                }
            }
        }
        return ans;
    }
};
