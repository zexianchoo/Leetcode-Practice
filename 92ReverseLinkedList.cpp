/* Created on 15 09 2023 - 11:11PM */ 
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        // Make dummy node:
        ListNode dum = ListNode(0, head);
        ListNode* dummy = &dum;
        // find prehead
        ListNode* prehead = dummy;
        for (int i = 0 ; i < left - 1; i += 1) {
            prehead = prehead->next;
        }
        ListNode* prev = prehead;
        ListNode* curr = prehead->next;
        // do swaps.
        for (int i = 0; i < right - left + 1; i += 1) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        // cout << curr->val << " " << prev->val << "\n";
        // link the two ends
        // curr should be the final node. 
        prehead->next->next = curr;
        prehead->next = prev;
        return dummy->next;
    }
};
