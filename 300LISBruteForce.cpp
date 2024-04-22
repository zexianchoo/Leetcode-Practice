/* Created on 18 04 2024 - 08:02PM */ 
class Solution {
public:
    // brute force
    int solve(vector<int>& nums, int i, int prev) {
        
        // base case:
        if (i >= nums.size()) { return 0; }
        // for each index we see, we will recurse and do solve
        int best;
        // case where we can take (i.e. nums[i] > prev)
        if (nums[i] > prev) {
            int take = 1 + solve(nums, i + 1, nums[i]);
            int dont_take = solve(nums, i + 1, prev);
            best = max(take, dont_take);
        }
        // if we can't take, we can only do don't take.
        else {
            int dont_take = solve(nums, i + 1, prev);
            best = dont_take;
        }
        return best;
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, INT_MIN);
    }
};
