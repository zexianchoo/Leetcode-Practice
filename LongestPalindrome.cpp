/* Created on 26 05 2023 - 07:50AM */ 
class Solution {
public:
    int longestPalindrome(string s) {
        
        // edge cases
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;
        std::unordered_map<char, int> counts;
        // fill counts
        for(unsigned int i = 0; i < s.size(); i += 1) {
            counts[s.at(i)] += 1;
        }
        // collect all letters which are mod 2. Keeps track if we have a center letter
        int res = 0;
        bool has_single = false;
        for (auto it = counts.begin(); it = counts.end(); it++) {
            // checks if there is more than 2
            if (it->second >= 2) {
                // add the num of multiples of 2 of the count
                res += it->second - it->second % 2;
                // check if has single
                if (has_single) {
                    has_single = it->second % 2 == 0 ? false : true;                
                }
            }
            else { has_single = true; }
        }
        // add 1 with has_single
        res = has_single ? res + 1 : res;
        return res;
    }
};
