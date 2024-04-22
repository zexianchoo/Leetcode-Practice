/* Created on 16 04 2024 - 00:56PM */ 
class Solution {
public:
    // We are at index n, so we rely on number of ways to get to n-1 and n-2.
    // We sum those up.
    int solve(int n) {
        if (n == 0) { return 1; }
        if (n < 0) { return 0; }
        int two_before = solve(n - 2);
        int one_before = solve(n - 1);
        
        return one_before + two_before;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};
