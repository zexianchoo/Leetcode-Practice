/* Created on 03 04 2024 - 10:13AM */ 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort by first:
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i += 1) {
            if (res.empty()) { res.push_back(intervals[i]); }
            else {
                // check vector.back - if the R of back > L or curr, update vector.back
                if (res.back()[1] >= intervals[i][0]) {
                    res.back()[1] = max(intervals[i][1], res.back()[1]);
                }
                else {
                    res.push_back(intervals[i]);
                }
            }
        }
        return res;
    }
};
