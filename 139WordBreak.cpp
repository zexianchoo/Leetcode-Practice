/* Created on 14 04 2024 - 09:27PM */ 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.size(); i += 1) {
            
            // loop through all words:
            for (auto word : wordDict) {
                // cant event fit word
                if (word.size() > i) { continue; }
                
                // if we can fit this word and dp[i - word.size()], then this is true.
                // check if this word fits from s[i - word.size()]
                if (s.find(word, i - word.size()) == i - word.size()) {
                    if (dp[i - word.size()]) { dp[i] = true; }
                }
            }
        }
        return dp[s.size()];
    }
};
