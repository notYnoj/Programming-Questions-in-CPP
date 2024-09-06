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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> hasN=0;
        for(int x: nums) hasN[x]=1;
        ListNode dummy(0, head);
        ListNode* prev=&dummy, *tmp=NULL;
        for(ListNode* curr=head; curr; curr=curr->next, delete tmp){
            if (hasN[curr->val]){ 
                prev->next = curr->next;
                tmp=curr;
            }
            else{
                prev = prev->next;
                tmp=NULL;
            }
        }
        return dummy.next;
    }
};
