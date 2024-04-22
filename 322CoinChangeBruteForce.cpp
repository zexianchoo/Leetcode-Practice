/* Created on 16 04 2024 - 06:55PM */ 
class Solution {
public:
    int solve(vector<int>& coins, int target, int num_coins) {
        // if we have exceeded, return dummy value
        if (target < 0) { return -1; }
        // we have found the value:
        if (target == 0) { return num_coins; }
        // if we havent found:
        int res = INT_MAX;
        // pick any coin and recurse
        for (int i = 0; i < coins.size(); i += 1) {
            int curr = solve(coins, target - coins[i], num_coins + 1);
            if (curr = -1) {
                res = min(res, curr);
            }
        }
        if(res == INT_MAX) { return -1; }
        return res;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        return solve(coins, amount, 0);
    }
};
