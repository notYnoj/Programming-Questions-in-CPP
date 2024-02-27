class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateDiameter(root, maxDiameter);
        return maxDiameter;
    }

private: 
    int calculateDiameter(TreeNode* root, int& maxDiameter) {
        if (!root)
            return 0;
        //basically calcualte the depth of a current node aka untill it reaches a leaf node, then at the current ndoe as the base
        //add the left and right 
        int leftDepth = calculateDiameter(root->left, maxDiameter);
        int rightDepth = calculateDiameter(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        // Return the depth of the current node
        //max between goign all the way down is the max depth of any node
        return 1 + max(leftDepth, rightDepth);
    }
};
