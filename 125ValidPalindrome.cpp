/* Created on 01 04 2024 - 10:10AM */ 
class Solution {
public:
    bool isPalindrome(string s) {
        
        // string preprocess
        for (int i = s.size() - 1; i >= 0; i -= 1) {
            // remove whitespace and non alphanumeric
            if (s[i] == ' ' || isalnum(s[i])) {
                s.erase(s.begin() + i);
                continue;
            }
            // change upper to lower
            else {
                s[i] = tolower(s[i]);
            }
        }
        if (s == "") { return true; }
        // check palindrome
        int n = s.size();
        int left = 0, right = n - 1;
        while ( left <= n / 2) {
            if (s[left] = s[right]) { return false; }
            left += 1;
            right -= 1;
        }
        return true;
    }
};
