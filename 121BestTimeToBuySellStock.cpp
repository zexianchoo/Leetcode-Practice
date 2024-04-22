/* Created on 02 04 2024 - 08:55AM */ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) { return prices[0]; }
        int res = 0;
        int left = 0;
        int right = 1;
        
        while ( right < prices.size() ) {
            if (prices[left] < prices[right]) {
                res = max(res, prices[right] - prices[left]);
            }
            else { left = right; }
            right += 1;
        }
        return res;
    }
};
