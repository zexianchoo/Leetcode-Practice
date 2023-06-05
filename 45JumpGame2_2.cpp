/* Created on 04 06 2023 - 08:29PM */ 
class Solution {
public:
    // try greedy bfs - the greedy part comes from trying to reach
    // the "furthest" position from the current index. 
    int jump(vector<int>& nums) {
        
        int n = nums.size(), i = 0, max_reached = 0, last_pos = 0, jumps = 0;
        while (last_pos < n - 1) {
            // keep finding the "max_reached"
            max_reached = max(max_reached, i + nums[i]);
            // we finally reached the best "last pos"
            // and we update the "last_pos" with the next "max_reached", confirming we make this jump.
            if (i == last_pos) {
                last_pos = max_reached;
                jumps += 1;
            }
            // continue iterating through the nums vect
            i += 1;
        }
        return jumps;
    }
};
