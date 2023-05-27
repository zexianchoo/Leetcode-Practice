/* Created on 27 05 2023 - 05:29PM */ 
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows;
        rows.push_back("qwertyuiop");
        rows.push_back("asdfghjkl");
        rows.push_back("zxcvbnm");
        vector<string> res;
        for (string word : words) {
            
            bool works = true;
            // check which row it is based on 
            for (int i = 0; i < rows.size(); i += 1) {
                
                // found the row
                if (rows[i].find(tolower(word[0])) :string::npos) {
                    
                    // check rest of chars
                    for(char charac : word) {
                        // if we cant find it, it doesnt work
                        if (rows[i].find(tolower(charac)) == std::string::npos) { works = false; }
                    }
                }
            }
            if (works) { res.push_back(word); }
        }
        return res;
    }
};
