/* Created on 02 10 2023 - 03:51PM */ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // I think I can try to use double pointers.
        if (s == "") { return 0; }
        unordered_map<char, int> counts;
        int l = 0, r = 0, max_length = 1;
        while (r < s.size()) {
            // greedily increment counts
            while (r < s.size() && counts.find(s[r]) == counts.end()) {
                counts[s[r]]++;
                r++;
            }
            r--;
            max_length = max(max_length, r - l + 1);
            // right shift the sliding window.
            if(counts[s[l]] > 1) {
                counts[s[l]]--;
            }
            else { counts.erase(s[l]); }
            r++;
            l++;
        }
        return max_length;
    }
};
