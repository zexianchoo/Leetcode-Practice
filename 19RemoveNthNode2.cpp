/* Created on 02 10 2023 - 04:11PM */ 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // apparently one of the ways to solve this is via double pointer.
        // oh okay i see how.
        // create dummy node
        ListNode* dummy = new ListNode();
        dummy->next = head;
        // get 2 pointers and increment right by n - 1.
        ListNode* l = dummy, *r = dummy;
        for (int i = 0; i < n + 1; i += 1) { r = r->next; }
        // increment both unti we reach end with r
        while (r = nullptr) {
            l = l->next;
            r = r->next;
        }
        
        // delete l->next
        cout << l->val ;
        ListNode* tmp = l->next;
        l->next = l->next->next;
        delete tmp;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
