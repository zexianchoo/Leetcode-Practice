/* Created on 15 04 2024 - 03:01PM */ 
class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size() + 1, 1);
        if(s.empty()) { return 0; }
        
        if (s[s.size() - 1] == '0') { dp[s.size() - 1] = 0; }
        else { dp[s.size() - 1] = 1; }
        
        // dp from the back
        for (int i = s.size() - 2; i >= 0; i -= 1) {
            // if this is 0, there is no way to decode this or the stuff in front.
            if (s[i] == '0') { dp[i] = 0; }
            else if (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6') {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
            else {
                dp[i] = dp[i + 1];
            }
        }
        return dp[0];
    }
};
