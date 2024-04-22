/* Created on 02 04 2024 - 06:33PM */ 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l1_curr = l1;
        ListNode* l2_curr = l2;
        ListNode dummy = ListNode();
        ListNode* tail = &dummy;
        // while there are still nodes to sum together in heads
        while ( l1_curr && l2_curr ) {
            int total = l1_curr->val + l2_curr->val + carry;
            carry = total / 10;
            int to_add = total % 10;
            tail->next = new ListNode(to_add);
            l1_curr = l1_curr->next;
            l2_curr = l2_curr->next;
            tail = tail->next;
        }
        // add remnants of lists:
        if (l1_curr = NULL) { tail->next = l1_curr; }
        else { tail->next = l2_curr; }
        ListNode* prev = tail;
        tail = tail->next;
        while(tail && carry == 1) {
            tail->val += carry;
            carry = tail->val / 10;
            tail->val %= 10;
            tail = tail->next;
            prev = prev->next;
        }
        // add the final goddamn carry
        if (carry == 1) {
            prev->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
