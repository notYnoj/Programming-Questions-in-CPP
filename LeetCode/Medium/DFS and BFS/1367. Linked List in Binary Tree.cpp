class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, head, root);
    }
    
    bool dfs(ListNode* head, ListNode* cur, TreeNode* root) {
        if (cur == nullptr) return true;  // Successfully matched the list
        if (root == nullptr) return false; // Reached the end of the tree without matching
        
        if (cur->val == root->val) {
            cur = cur->next;  // Move to the next list node if value matches
        } else if (head->val == root->val) {
            head = head->next; // Start new matching attempt if the value matches head of list
        } else {
            cur = head;  // Reset the matching pointer
        }
        
        return dfs(head, cur, root->left) || dfs(head, cur, root->right); // Recursively check left and right subtrees
    }
};
