class Solution {
public:
    int maxHeightAfterRemoval[100001];
    int currentMaxHeight = 0;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;
        traverseRightToLeft(root, 0);

        int queryCount = queries.size();
        vector<int> queryResults(queryCount);
        for (int i = 0; i < queryCount; i++) {
            queryResults[i] = maxHeightAfterRemoval[queries[i]];
        }

        return queryResults;
    }

private:
    void traverseLeftToRight(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        maxHeightAfterRemoval[node->val] = currentMaxHeight;
        currentMaxHeight = max(currentMaxHeight, currentHeight);

        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    void traverseRightToLeft(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        maxHeightAfterRemoval[node->val] = 
            max(maxHeightAfterRemoval[node->val], currentMaxHeight);
        currentMaxHeight = max(currentHeight, currentMaxHeight);

        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};
