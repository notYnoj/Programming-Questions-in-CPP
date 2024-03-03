class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
    
    // Move the first pointer n+1 steps forward
        for (int i = 0; i < n + 1; ++i) {
            first = first->next;
        }
    
    // Move both pointers until the first pointer reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
    
    // Remove the nth node
        second->next = second->next->next;
    
        return dummy->next;
    }
};
//Honestly linked lists are so bad
