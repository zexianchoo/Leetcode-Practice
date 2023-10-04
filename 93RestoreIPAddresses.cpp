/* Created on 21 09 2023 - 00:08AM */ 
class Solution {
public:
    // backtracking problem with some sort of dp? or storage of locationin str.
    void recurse(vector<string>& res, const string& s, string curr, unsigned num_parts, unsigned idx) {
        // base case -1: more parts than 4
        if (num_parts > 4) return;
        
        // base case 0: end of string
        if (idx == s.size()) { 
            if (num_parts == 4) {
                res.push_back(curr.substr(0, curr.size() - 1));
            }
            return; }
        if (idx > s.size()) { return; }
        
        // base case 1: leading zero means add only the 0.
        if (s.at(idx) == '0') { 
            curr.append("0.");
            recurse(res, s, curr, num_parts + 1, idx + 1); 
            return;
        }
        // recurse
        for (int i = 1; i < 4; i += 1) {
            
            // for all checks where we are within the 
            if (idx + i <= s.size()) {
                // check for 255
                string adding = s.substr(idx, i);
                cout << "adding" << adding << " ";
                if (stoi(adding) <= 255 ) {
                    curr.append(adding);
                    curr.append(".");
                    recurse(res, s, curr, num_parts + 1, idx + i);
                    curr = curr.substr(0, curr.size() - i - 1);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        recurse(res, s, "", 0, 0);
        
        return res;
    }
};
