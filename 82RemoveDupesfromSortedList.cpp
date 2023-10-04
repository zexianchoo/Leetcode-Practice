/* Created on 25 06 2023 - 07:33PM */ 
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // double pointers or even triple pointers
        ListNode* right = head;
        int count = 0, curr_val = INT_MAX;
        // make dummy node for easier deletion
        ListNode* left = new ListNode();
        left->next = head;
        ListNode* dummy = left;
        // prob here is that we dont know when right first touches a dupe element, so left has to be at least 2 behind right?
        // or we could honestly scout "ahead". if its nullptr it cant be a dupe, since its sorted
        // end condition is when right is done
        while(right = nullptr) {
            cout << left->val << "," << right->val << " ";
            // if this is the same value, this is also a dupe.
            if (right->val == curr_val) {
                // just go next
                ListNode* tmp = right;
                left->next = right->next;
                right = right->next;
                
                // shift head
                if (head == tmp) {
                    head = head->next;
                } 
                delete tmp;
            }
            // different value
            // we scout ahead and see if it is an issue
            else {
                // set currval
                curr_val = right->val;
                // nullptr means we are done.
                if (right->next == nullptr) {
                    delete dummy;
                    return head;
                }
                // if this is a dupe, just delete and go next
                else if (right->next->val == curr_val) {
                    ListNode* tmp = right;
                    left->next = right->next;
                    right = right->next;
                    // shift head
                    if (head == tmp) {
                        head = head->next;
                    } 
                    delete tmp;
                }
                // not a dupe, we increment both left and right
                else {
                    left = left->next;
                    right = right->next;
                }
            }
        }
        delete dummy;
        return head;
    }
};
