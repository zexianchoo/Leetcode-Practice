/* Created on 03 04 2024 - 09:20AM */ 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        bool placed = false;
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i += 1) {
            // if the new interval's right is less than the current interval's left, it doesnt overlap
            if (newInterval[1] < intervals[i][0]) {
                if (placed) {
                    res.push_back(newInterval);
                    placed = true;
                }
                res.push_back(intervals[i]);
            }
            else if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            }
            // we are merging
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        if (placed) { res.push_back(newInterval); }
        return res;
    }
};
