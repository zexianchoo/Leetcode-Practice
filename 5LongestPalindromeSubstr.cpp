/* Created on 28 05 2023 - 07:52AM */ 
class Solution {
public:
/* 
    idea:
    since we know that palindromes must start/ end by the same letter, and each 
    palindrome is another palindrome inside, for each char, we can work outwards til we meet a mismatch. 
*/
    int helperCount(int pos, const string& s) {
        int back_int = pos - 1;
        int front_int = pos + 1;
        int res_odd = 1, res_even = 0;
        
        // check that this is the odd
        while(back_int >= 0 && front_int < s.size() && s[back_int] == s[front_int]) {
            res_odd += 2;
            back_int -= 1;
            front_int += 1;
        }
        // check if this is even
        front_int = pos + 1;
        back_int = pos;
        while(back_int >= 0 && front_int < s.size() && s[back_int] == s[front_int]) {
            res_even += 2;
            back_int -= 1;
            front_int += 1;
        }
        return max(res_odd, res_even);
    }
    string longestPalindrome(string s) {
        int max_len = -1;
        int max_pos = -1;
        if (s.size() == 1) { return s; }
        
        for (int i = 0; i < s.size(); i += 1) {
            int len = helperCount(i, s);
            
            // update max len
            if (len > max_len) {
                max_len = len;
                max_pos = i;
            }
        } 
        // return largest str
        std::cout << max_len << " " << max_pos << "\n";
        // even case:
        if (max_len % 2 == 0) { 
            return s.substr(max_pos - max_len / 2 + 1, max_len);
        }
        else { return s.substr(max_pos - max_len / 2, max_len); }
    }
};
