class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* second = head;
        int count = 0; 

        while (second) {
            count++;
            second = second->next;
        }

        second = head;

        int middleIndex = count / 2;

        for (int i = 0; i < middleIndex; ++i) {
            second = second->next;
        }

        return second;
    }
};
