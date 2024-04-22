	/* Created on 16 04 2024 - 10:24AM */ 
class Solution {
public:
    int recurse(vector<int>& nums, vector<vector<int>>& memo, int idx, int prev_idx) {
        // base case
        if (idx >= nums.size()) {
            return 0;
        }
        int res;
        // if this has been calcualted befoe
        if (memo[idx][prev_idx + 1] != -1) {
            return memo[idx][prev_idx + 1];
        }
        
        // recursively search the space, take or dont take:
        else if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            int take = recurse(nums, memo, idx + 1, idx) + 1;
            int dont_take = recurse(nums, memo, idx + 1, prev_idx);
            res = max(take, dont_take);
        }
        else {
            res = recurse(nums, memo, idx + 1, prev_idx);
        }
        // asign to memo:
        memo[idx][prev_idx + 1] = res;
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        int res = recurse(nums, memo, 0, -1);
        return res;
    }
};
