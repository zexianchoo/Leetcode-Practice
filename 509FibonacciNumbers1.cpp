/* Created on 01 10 2023 - 07:23PM */ 
class Solution {
public:
    // memoization
    int fib(int n) {
        int dp[n + 1]; 
        for (int i = 0; i <= n; i += 1) {
            if (i == 0) { dp[0] = 0; }
            else if (i == 1) { dp[1] = 1; }
            else {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }
};
