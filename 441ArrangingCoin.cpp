/* Created on 26 05 2023 - 02:01PM */ 
class Solution {
public:
    // counts total counts given n number of rows
    long totalCoins(long rows) {
        return (rows * (rows + 1)) >> 1;
    }
    int arrangeCoins(int n) {
        
        // try bin search
        long left, right;
        long rows;
        int ans;
        left = 1, right = n;
        // bin search
        while (left <= right) {
            rows = (right + left) >> 1;
            long num_coins = totalCoins(rows);
            if (num_coins <= n) {
                left = rows + 1;
                ans = rows;
            }
            else right = rows - 1;
        }
        return ans;
    }
};
