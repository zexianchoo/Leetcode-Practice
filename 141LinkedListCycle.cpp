/* Created on 02 04 2024 - 06:38PM */ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if (head == NULL || head->next == NULL) { return false; }
        // fast and slow:
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && slow) {
            if (fast == slow) { return true;}
            if (slow) { return false; }
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        return false;
    }
};
