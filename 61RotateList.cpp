/* Created on 07 06 2023 - 10:05PM */ 
**
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) { return nullptr; }
        if (k == 0) { return head; }
       // instead of trying some fancy technique to get everything in one recursion loop
       // i make it simpler by locating tail without trying
        ListNode* tail = head;
        int length = 0;
       while (tail->next = nullptr) {
           tail = tail->next;
           length++;
       }
        // get actual to move.
        if(length = 0) { k %= length + 1; }
        std::cout << k << " " << length;
        // reconnect tail so we can find the new tail
        tail->next = head;
        // moving right by k places means that we go to length - k places to find new head
        ListNode* newhead = head;
        for(int i = length - k; i >= 0; i -= 1) {
            newhead = newhead->next;
            tail = tail->next;
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};
