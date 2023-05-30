/* Created on 28 05 2023 - 06:19AM */ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // fancy pants solution with similar idea i had in the past
        vector<int> seen(256, -1);
        int max_len = 0, start = -1;
        
        for (int i = 0; i < s.size(); i += 1) {
            // update start if we saw this before
            if (seen[s[i]] > start) {
                start = seen[s[i]];
            }
            // update the vector to the curr position
            seen[s[i]] = i;
            // update max length
            max_len = max(max_len, i - start);
        }
        return max_len;
    }
};
