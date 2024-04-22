/* Created on 02 04 2024 - 05:01PM */ 
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
    void reorderList(ListNode* head) {
        
        // instead of recursion, have an explciit stack
        stack<ListNode*> s;
        ListNode* curr = head;
        int count = 0;
        while (curr) {
            s.push(curr);
            curr = curr->next;
            count += 1;
        }
        // create dummy:
        ListNode dummy = ListNode();
        curr = &dummy;
        for (int i = 0; i < count / 2; i += 1) {
            curr->next = head;
            head = head->next;
            curr->next->next = s.top();
            curr = s.top();
            s.pop();
        }
        // edge
        if (head == s.top()) {
            curr->next = head;
            curr = head;
        }
        curr->next = NULL;
        head = dummy.next;
    }
};
