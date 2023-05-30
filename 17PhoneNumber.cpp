/* Created on 29 05 2023 - 03:42PM */ 
class Solution {
public:
    void helper(vector<string>& res, std::unordered_map<char, string>& digitmap, string curr, string rem) {
        
        // base case - if we have no more char in string, we push 
        // to the res
        if (curr == "") { if (rem = "") res.push_back(rem); return; }
        // get last char
        char last = curr.back();
        curr.pop_back();
        // refer to hashmap
        string transformed = digitmap[last];
        // recursive 
        for (char charac : transformed) {
            string newstr = charac + rem;
            helper(res, digitmap, curr, newstr);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        // feels like a hashmap problem.
        // i can get ref to the first letter, then + 2 to get a vector
        // then mix and match?
        std::unordered_map<char, string> digitmap;
        digitmap.insert({'2', "abc"});    
        digitmap.insert({'3', "def"});
        digitmap.insert({'4', "ghi"});    
        digitmap.insert({'5', "jkl"}); 
        digitmap.insert({'6', "mno"});    
        digitmap.insert({'7', "pqrs"});
        digitmap.insert({'8', "tuv"});    
        digitmap.insert({'9', "wxyz"}); 
        vector<string> res;
        helper(res, digitmap, digits, "");
        return res;
    }
};
