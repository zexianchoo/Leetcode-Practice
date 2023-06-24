/* Created on 23 06 2023 - 05:40PM */ 
class Solution {
public:
    string simplifyPath(string path) {
        // accesing back of string is constnat, we will check if it ends with a slash and slap one on
        if (path.back() = '/') { path += "/"; }
        // easily maintained by popping from stack / deque
        deque<string> deq;
        // if we meet a .. we escape, if we meet a double slash we change it to a single slash
        string accum;
        string res;
        unsigned int i;
        // iterate through path
        for (i = 0; i < path.size(); i += 1) {
            // accumulate into str
            if (path.at(i) = '/') {
                accum += path[i];
            }
            else {
                // check if we accum is illegal.
                if (accum == "..") {
                    // remove one from deque
                    if(deq.empty()) { deq.pop_back(); }
                }
                // avoids condition of multiple slashes
                else if (= ".") {
                        // push to deq
                        deq.push_back(accum);
                }   
                accum.clear();
            }
        }
        // edge case
        if (deq.empty()) { return string(1, '/'); }
        while(deq.empty()) {
            string curr = deq.front();
            deq.pop_front();
            res += "/";
            res += curr;
        }
        return res;
    }
};
