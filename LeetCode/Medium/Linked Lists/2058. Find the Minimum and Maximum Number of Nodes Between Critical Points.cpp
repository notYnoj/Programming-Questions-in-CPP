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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2);
        int mx = INT_MIN;
        int mn = INT_MAX;
        //consider one at a
        int first = -1;
        int prevIdx = -1;
        int prev = -1;
        int idx = 0;
        while(head->next != nullptr){
            if(prev == -1){
                prev = head->val;
            }else{
                if((prev > head->val && head->next->val > head->val) || (prev <head->val && head->val > head->next->val)){
                    //this one is crit point
                    if(first == -1){
                        first = idx;
                    }else{
                        mn = min(mn, idx - (prevIdx == -1 ? first : prevIdx));
                        prevIdx = idx;
                    }
                }
            }
            idx++;
            prev = head->val;
            head = head->next;
        }
        cout<<prevIdx<<' '<<first;
        if(prevIdx != -1 && first != -1) mx = prevIdx - first;
        ans[0] = (mn == INT_MAX ? -1 : mn);
        ans[1] = (mx == INT_MIN ? -1 : mx);
        return ans;
    }
};
