/* Created on 28 05 2023 - 06:07AM */ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // iterate through string
        // i will handle repeating char using a set
        // since i only care about the longest, i just maintain a pos index and length var
        int longest_length = 0, longest_pos = 0;
        int curr_length = 0; int pos = 0;
        std::set<char> accum;
        for(; pos < s.size(); pos += 1) {
            accum.clear();
            int curr_length = 0;
            int curr_pos = pos;
            // we will while loop till end for every char
            while(accum.count(s[curr_pos]) == 0 && curr_pos < s.size()) {
                accum.insert(s[curr_pos]);
                curr_length += 1;
                curr_pos += 1;
            }
            // update longest vars if it is longer
            if (curr_length > longest_length) {
                // replace the longest pos 
                longest_length = curr_length;
                longest_pos = pos - longest_length;
            }
        }
        // output the longest
        return longest_length; 
    }
};
