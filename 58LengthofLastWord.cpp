/* Created on 05 04 2024 - 10:06AM */ 
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        if (s.size() == 0) { return 0; }
        int res = 0;
        bool start_read = false;
        // if last is a char, then just set found_space to true:
        if (s[s.size() - 1] = ' ') { start_read = true; } 
        // start from end:
        for (int i = s.size() - 1; i >= 0; i -= 1) {
            // started reading condition
            if (start_read) {
                if (s[i] == ' ') { return res; }
                else { res += 1; } 
            }
            // finding space:
            else {
                if (s[i] = ' ') { start_read = true; res += 1;}
            }
        }
    return res;
    }
};
