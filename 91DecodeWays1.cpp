/* Created on 15 09 2023 - 10:00PM */ 
class Solution {
public:
    int numDecodings(string s) {
        
        // initialie vector
        vector<int> dp = vector<int>(s.size() + 1, 1);
        dp[s.size()] = 1;
        // iterate through in reverse
        for (int i = s.size() - 1; i >= 0; i--) {
            // impossible and cut off all possible routes
            if (s[i] == '0') dp[i] = 0;
            else {
                // normal progression - no increment in count
                dp[i] = dp[i + 1];
                // add the num ways of 2 forward
                if (i < s.size() - 1 && (s[i] == '1' || s[i] ==  '2' && s[i + 1] < '7')) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return s.empty() ? 0 : dp[0];
    }
};
