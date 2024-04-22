/* Created on 01 04 2024 - 08:54PM */ 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res (temperatures.size(), 0);
        s.push(0);
        for (int i = 1; i < temperatures.size(); i += 1) {
            // using this current node, check if its larger than stack top
            while (s.empty() && temperatures[s.top()] < temperatures[i]) {
                // if larger, pop off and assign res at index to distnace
                int old_idx = s.top();
                s.pop();
                res[old_idx] = i - old_idx;
            }
            s.push(i);
        }
        return res;
    }
};
        
