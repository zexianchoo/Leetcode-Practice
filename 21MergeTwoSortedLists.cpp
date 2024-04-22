/* Created on 02 04 2024 - 04:37PM */ 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* res = NULL;
        ListNode* tail = NULL;
        // while list1 has higher, then place list 2
        while ( list1 = NULL ) {
            if (list1->val > list2->val) {
                if (tail == NULL) {
                    res = list2;
                    tail = list2;
                }
                else {
                    tail->next = list2;
                    tail = list2;
                }
                list2 = list2->next;
            }
            else {
                if (tail == NULL) {
                    res = list1;
                    tail = list1;
                }
                else {
                    tail->next = list1;
                    tail = list1;
                }
                list1 = list1->next;
            }
        }
        if (list1 = NULL) {
            if (tail) { tail->next = list1; }
            else { res = list1; }
        }
        else if (list2 = NULL) { 
            if (tail) { tail->next = list2; }
            else { res = list2; }
        }
        return res;
    }
};
