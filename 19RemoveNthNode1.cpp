/* Created on 02 10 2023 - 04:03PM */ 
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
    int recurse(ListNode* curr, int n) {
        if (curr == nullptr) { return 0; }
        int next_node_depth = recurse(curr->next, n);
        // here, if next node_depth is n , then we wil have to carry out some sort of removal.
        // delete node
        if (next_node_depth == n) {
            ListNode* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        }
        return next_node_depth + 1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // i remember this can be done with recursion and using the stack to reverse the nodes.
        // is there a simpler solution?
        // let me just get it corret first tbh.
        // create dummy node
        ListNode* dummy = new ListNode(); dummy->next = head;
        recurse(dummy, n);
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
