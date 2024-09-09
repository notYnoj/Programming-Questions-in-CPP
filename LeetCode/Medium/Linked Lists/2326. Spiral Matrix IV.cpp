/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize matrix with -1
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* curr = head;

        // Traverse the matrix in spiral order
        while (curr != nullptr && top <= bottom && left <= right) {
            
            // Fill top row (left to right)
            for (int i = left; i <= right && curr != nullptr; i++) {
                ans[top][i] = curr->val;
                curr = curr->next;
            }
            top++;
            
            // Fill right column (top to bottom)
            for (int i = top; i <= bottom && curr != nullptr; i++) {
                ans[i][right] = curr->val;
                curr = curr->next;
            }
            right--;
            
            // Fill bottom row (right to left)
            for (int i = right; i >= left && curr != nullptr; i--) {
                ans[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;
            
            // Fill left column (bottom to top)
            for (int i = bottom; i >= top && curr != nullptr; i--) {
                ans[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }

        return ans;
    }
};
