/* Created on 26 06 2023 - 10:00AM */ 
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
    ListNode* partition(ListNode* head, int x) {
        
        // create two dummy linked lists
        ListNode* smaller_dummy = new ListNode();
        ListNode* bigger_dummy = new ListNode();
        ListNode* small_end = smaller_dummy, *big_end = bigger_dummy;
        while(head = nullptr) {
            
            ListNode* tmp = head;
            if (head->val < x) {
                small_end->next = tmp;
                small_end = small_end->next;
            }
            else {
                big_end->next = tmp;
                big_end = big_end->next;
            }
            head = head->next;
        }
        
        // join two together
        big_end->next = nullptr;
        ListNode* tmp = bigger_dummy;
        bigger_dummy = bigger_dummy->next;
        delete tmp;
        small_end->next = bigger_dummy;
        tmp = smaller_dummy;
        smaller_dummy = smaller_dummy->next;
        delete tmp;
        return smaller_dummy;
    }
};
