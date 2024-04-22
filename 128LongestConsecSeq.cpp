/* Created on 01 04 2024 - 09:28AM */ 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // get rid of edge case
        if (nums.empty()) { return 0; }
        unordered_map<int, int> counts;
        // add elements to map:
        for (unsigned int i = 0; i < nums.size(); i += 1) {
            counts[nums[i]] = 1;
        }
        // go through map, and remove single nodes
        for (unsigned int i = 0; i < nums.size(); i += 1) {
            if (counts.contains(nums[i] - 1)) {
                counts[nums[i]] = 0;
            }
        } 
        int res = INT_MIN;
        // go through array again and get max val
        for (unsigned int i = 0; i < nums.size(); i += 1) {
            if (counts[nums[i]] == 1) {
                int curr_streak = 1;
                // while the next is streaky
                while (counts.contains(nums[i] + curr_streak)) {
                    curr_streak += 1;
                }
                // update max val
                if (curr_streak > res) { res = curr_streak; }
            }
        }
        return res;
    }
};
