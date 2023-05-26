/* Created on 25 05 2023 - 06:31PM */ 
class Solution {
public:
    char findTheDifference(string s, string t) {
       // sum and get char.
       for (int i = 0; i < s.size(); i += 1) {
           t[i+1] += t[i] - s[i];
       } 
        return t[t.size()-1];       
    }
};
