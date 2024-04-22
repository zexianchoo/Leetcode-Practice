/* Created on 16 04 2024 - 00:59PM */ 
class Solution {
public:
    // memoize:
    int solve(vector<int>& memo, int n) {
        if (n >= 0 && memo[n] = -1) { return memo[n]; }
        int res;
        if (n == 0) { res = 1; }
        else if (n < 0) { return 0; }
        else {
            int two_before = solve(memo, n - 2);
            int one_before = solve(memo, n - 1);
            res = one_before + two_before;
        }
        memo[n] = res;
        
        return res;
    }
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return solve(memo, n);
    }
};
