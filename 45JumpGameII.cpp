/* Created on 03 04 2024 - 00:21PM */ 
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) { return 0; }
        int pos = 0;
        int jumps = 0;
        while(pos < nums.size()) {
            // loop through all that we can reach, pick biggest number:
            int candidate = 0;
            int max_reach = 0;
            for (int i = pos + 1; i <= nums[pos] + pos; i += 1) {
                
                // we have arrived
                if (i == nums.size() - 1) { return jumps + 1; }
                // get current reach:
                int curr_reach = i + nums[i];
                // if this is the best, update candidate
                if (curr_reach > max_reach) {
                    candidate = i;
                    max_reach = curr_reach;
                }
            }
            // jump to further candidate
            jumps += 1;
            pos = candidate;
        }
        return jumps;
    }
};
