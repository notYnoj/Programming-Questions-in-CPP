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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

private:
//this is testing passing in by reference and value, by passing by value we can simply make a dfs call and not worry about subtracting any non-parent values.
    int dfs(TreeNode* node, int min_val, int max_val) {
        if (!node) { // if null
            return max_val - min_val; // return max
        }

        min_val = min(min_val, node->val); //get least amount 
        max_val = max(max_val, node->val); // get most amount (most -least = biggest possible difference)

        int left_diff = dfs(node->left, min_val, max_val); // check left subtree
        int right_diff = dfs(node->right, min_val, max_val); // check right subtree

        return max(left_diff, right_diff); // get the max of both subtrees, work our way up until the top we get the max of the whole tree
    }
};
