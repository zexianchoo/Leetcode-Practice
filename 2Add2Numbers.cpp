/* Created on 28 05 2023 - 05:38AM */ 
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
 /*
942 + 9465 = 
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // just solve using brute force first bc i dont have the brains
        // reverse using stack
        std::queue<int> s1, s2;
        // iterate trhough btoh lists and add to stack
        while(l1 = nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 = nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        // make the first one so we can preserve the ListNode
        int carry = 0;
        int toadd = s1.front() + s2.front();
        std::cout << s1.front() << " " << s2.front() << "\n";
        if (toadd >= 10) { carry = 1; toadd = toadd % 10; }
        else { carry = 0; }
        // add the two and make a new listnode
        ListNode* res = new ListNode(toadd);
        s1.pop(); s2.pop();
        ListNode* curr = res;
        // pop out from stacks and make new nodes as we continue
        while(s2.empty() || carry >= 1) {
            int val1, val2;
            if (s1.empty()) { 
                val1 = 0;
            }
            else { val1 = s1.front(); s1.pop(); }
            if (s2.empty()) { 
                val2 = 0;
            }
            else { val2 = s2.front(); s2.pop(); }
            // add to carry
            toadd = val1 + val2 + carry;
            if (toadd >= 10) { carry = 1; toadd = toadd % 10; }
            else { carry = 0; }
            // add the two and make a new listnode
            curr->next = new ListNode(toadd);
            curr = curr->next;
        }
        return res;
    }
};
