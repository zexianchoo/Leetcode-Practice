/* Created on 16 04 2024 - 05:28PM */ 
class Solution {
public:
    // brute force
    int solve(vector<int>& nums, int n, bool chose_first) {
        if (n < 0) { return 0; }
        // if we cant take the first
        if (chose_first && n == 0) { return 0; }
        int max_from_two_before = solve(nums, n - 2, chose_first) + nums[n];
        int max_from_one_before = solve(nums, n - 1, chose_first);
        return max(max_from_two_before, max_from_one_before);
    }
    // brute force method:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) { return nums[0]; }
        // two options: rob first or dont rob first.
        // if we rob first, we cannot take n. Call solve on n - 1
        // if we dont, we can take n.
        int choose_first = solve(nums, n - 2, true);
        int dont_choose_first = solve(nums, n - 1, false);
        return max(choose_first, dont_choose_first);
    }
};
