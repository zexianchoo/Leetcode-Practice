/* Created on 01 04 2024 - 09:40AM */ 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        int res = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for (unsigned int i = 0; i < nums.size(); i += 1) {
            if (set.find(nums[i]) == set.end()) { continue; }
            int prev = nums[i] - 1;
            int next = nums[i] + 1;
            // while we find a next element in streak, remove elements from set
            while(set.find(next) = set.end()) {
                set.erase(next);
                next += 1;
            }
            while(set.find(prev) = set.end()) {
                set.erase(prev);
                prev -= 1;
            }
            // find res
            res = max(res, next - prev - 1);
        }
        return res;
    }
};
