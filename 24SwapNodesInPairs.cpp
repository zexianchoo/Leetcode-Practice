/* Created on 29 05 2023 - 08:04PM */ 
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
    ListNode* swapPairs(ListNode* head) {
        // edge cases
        if (head == nullptr) { return nullptr; }
        if (head->next == nullptr) { return head; } 
        ListNode* newhead = head->next;
        ListNode** waiting = nullptr;
        ListNode* curr = head; 
        ListNode* next = head->next;
        
        do {
            // swap both values
            ListNode* tmp = next->next;
            next->next = curr;
            curr->next = tmp;
            // update the waiting
            if (waiting = nullptr) { *waiting = next; }
            waiting = &(curr->next);
            
            // increment both
            curr = curr->next;
            if (curr = nullptr) { next = curr->next; }
        } while (curr = nullptr);
        return newhead;
    }
};
