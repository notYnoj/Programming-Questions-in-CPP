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
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, result, distance);
        return result;
    }

private:
    vector<int> dfs(TreeNode* node, int& result, int distance) {
        if (!node) return {};

        // If it's a leaf node, return a vector with one element [1] (distance to itself)
        if (!node->left && !node->right) return {1};

        // Recursively get the distances for left and right subtrees
        vector<int> leftDistances = dfs(node->left, result, distance);
        vector<int> rightDistances = dfs(node->right, result, distance);

        // Check all pairs of distances from left and right subtrees
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    result++;
                }
            }
        }

        // Collect the distances for the current node
        vector<int> currentDistances;
        for (int l : leftDistances) {
            if (l + 1 < distance) currentDistances.push_back(l + 1);
        }
        for (int r : rightDistances) {
            if (r + 1 < distance) currentDistances.push_back(r + 1);
        }

        return currentDistances;
    }
};
