/* Created on 01 10 2023 - 06:11PM */ 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        // theres not much we can really do without extra space. the minimum is O(n).
        // the only O(1) space method i can think about is actually just recursion.
        k %= nums.size();
        // lets just solve this with extra space. I am thinking a deque
        deque<int> deq;
        // iterate through nums and push to deq
        for (auto it : nums) {
            deq.push_back(it);
        }
        int counter = 0;
        stack<int> s;
        // get all the reversed part
        while(k > 0) {
            s.push(deq.back());
            deq.pop_back();
            k -= 1;
        }
        
        // reverse this part with a stack
        
        while(s.empty()) {
            nums[counter] = s.top();
            counter += 1;
            s.pop();
        }
        // rest of the normal part
        while(deq.empty()) {
            nums[counter] = deq.front();
            deq.pop_front();
            counter += 1;
        }
    }
};
