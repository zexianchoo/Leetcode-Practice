/* Created on 05 06 2023 - 06:39PM */ 
class Solution {
public:
    bool canJump(vector<int>& nums) {
       // doesnt look like theres a greedy solution to this?  
       int max_reachable = nums[0], last_jumped = 0, curr = 0;
       int max_size = nums.size() - 1;
       // try to one pass greedy method, same concept as jumpgame 2
       while(max_reachable < max_size) {
           // update max_reachable
           if (curr + nums[curr] > max_reachable) { max_reachable = curr + nums[curr]; }
            if (curr == max_reachable) { return false; }
           // continue iterating
           curr += 1;
           
       }
       return true;
    }
};
