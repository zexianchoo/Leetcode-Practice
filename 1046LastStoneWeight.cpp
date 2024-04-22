/* Created on 03 04 2024 - 08:46AM */ 
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i += 1) {
            pq.push(stones[i]);
        }
        // to help edge case
        pq.push(0);
        while(pq.size() > 1) {
            int top = pq.top();
            pq.pop();
            int next = pq.top();
            pq.pop();
            if (top == next) { continue; }
            // stone survives
            top -= next;
            pq.push(top);
        }
        return pq.top();
    }
};
