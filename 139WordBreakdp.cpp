/* Created on 18 04 2024 - 07:47PM */ 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { 
        int n = s.size();
        vector<bool> dp(n + 1, false);
        // base case, just set 0 to true
        dp[n] = true;
        // iterate through the string
        for (int i = n - 1; i >= 0; i -= 1) {
            // at every index, try to fit a word:
            for (auto word : wordDict) {
                int word_len = word.size();
                // does not fit
                if (i + word_len > n) { continue; }
                // if it does fit, check if it is a match.
                // if match, return true && whatever was before:
                if (s.compare(i, word_len, word) == 0) {
                    dp[i] = dp[i] || dp[i + word_len];
                }
            }
        }
        return dp[0];
    }
};
