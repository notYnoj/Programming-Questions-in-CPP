class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isEqual(p, q);
    }
    
    bool isEqual(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        return isEqual(p->left, q->left) && isEqual(p->right, q->right);
    }
};
