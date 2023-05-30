/* Created on 29 05 2023 - 04:56PM */ 
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
    int helper(ListNode*& res, ListNode* curr, int n) {
        
        // base case
        if (curr == nullptr) { return 0; }
        int curr_sum = helper(res, curr->next, n);
        
        // update res with the node before target
        if (n == curr_sum) { res = curr; }
        return curr_sum + 1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // create pad for easy remove of head
        ListNode* pad = new ListNode(0, head); 
        ListNode* res = nullptr;
        helper(res, pad, n);
        // remove and return head
        ListNode* tmp = res->next;
        res->next = tmp->next;
        // event that we deleted head
        if (tmp == head) {
            head = head->next;
        }
        delete tmp; delete pad;
        return head;
    }
};
