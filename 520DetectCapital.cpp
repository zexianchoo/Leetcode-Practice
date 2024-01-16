/* Created on 30 11 2023 - 07:43PM */ 
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1) { return true; }
        // easiest is to check if we go into 3 decision paths
        // first letter is capital
        if (isupper(word[0])) {
            // second letter is capital
            if (isupper(word[1])) {
                for (unsigned int i = 2; i < word.size(); i += 1) {
                    if (isupper(word[i])) { return false; }
                }
            }
            // second letter not capital
            else {
                
                for (unsigned int i = 2; i < word.size(); i += 1) {
                    if (isupper(word[i])) { return false; }
                }
            }
        }
        else {
            for (unsigned int i = 1; i < word.size(); i += 1) {
                    if (isupper(word[i])) { return false; }
            }
        }
        return true;
    }
};
