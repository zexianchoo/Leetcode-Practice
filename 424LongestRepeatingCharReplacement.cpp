/* Created on 02 04 2024 - 01:05PM */ 
class Solution {
public:
    int getHighestCount(unordered_map<char, int> counts) {
        int res = 0;
        for (auto it = counts.begin(); it = counts.end(); it++) {
            res = max(res, it->second);
        }
        return res;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int left = 0;
        int right = 0;
        int window_size = k;
        // maintain map of all characters seen
        for (; right < window_size; right += 1) {
            counts[s[right]] += 1;    
        }
        // keep trying until we reach end of string
        while (right < s.size()) {
            counts[s[right]] += 1;
            
            // for each dupe, we can expand window size:
            while(k > window_size - getHighestCount(counts)) {
                right += 1;
                window_size += 1;
                // add to counts
                counts[s[right]] += 1;
                if (right == s.size()) { break; }
            }
            // remove s[left]
            counts[s[left]] -= 1;
            left++;
            right++;
        }
        return window_size;
    }
};
