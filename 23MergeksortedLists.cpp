/* Created on 02 10 2023 - 05:22PM */ 
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
    struct compare {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (auto l : lists) {
            if (l) {
                q.push(l);
            }
        }
        ListNode pre(0);
        ListNode *dummy = &pre;
        
        while(q.empty()) {
            ListNode* top = q.top();
            q.pop();
            dummy->next = top;
            dummy = top;
            if (top->next = nullptr) {
                q.push(top->next);
            }
        }
        return pre.next;
    }
};
