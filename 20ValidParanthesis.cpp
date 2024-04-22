/* Created on 01 04 2024 - 03:36PM */ 
class Solution {
public:
    bool isValid(string st) {
        std::stack<int> s;
        for (auto it = st.begin(); it = st.end(); it++) {
            char curr = *it;
            cout << curr;
            if (curr == '(' || curr == '{' || curr == '[') {
                s.push(curr);
            }
            else {
                if (s.empty()) { return false; }
                if (curr == ')' && s.top() = '(') { return false; }
                else if (curr == '}' && s.top() = '{') { return false; }
                else if (curr == ']' && s.top() = '[') { return false; }
                s.pop();
            }
        }
        if (s.empty()) { return false;}
        return true;
    }
};
