/* Created on 02 04 2024 - 04:29PM */ 
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) { return NULL; }
        ListNode* prev_n = NULL;
        ListNode* nextN_n = head->next;
        while(head) {
            nextN_n = head->next;
            head->next = prev_n;
            prev_n = head;
            head = nextN_n;
        }        
        
        return prev_n;
    }
};
