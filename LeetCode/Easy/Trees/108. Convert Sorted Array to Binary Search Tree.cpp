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
//Basically keep splitting into mids, go left and right wiht -> left/right and add to root.
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        int mid = nums.size() / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> leftSubarray(nums.begin(), nums.begin() + mid);
        vector<int> rightSubarray(nums.begin() + mid + 1, nums.end());

        root->left = sortedArrayToBST(leftSubarray);
        root->right = sortedArrayToBST(rightSubarray);

        return root;

    }
};
