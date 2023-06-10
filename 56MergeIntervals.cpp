/* Created on 05 06 2023 - 07:36PM */ 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        // sort by first number in each interval
        sort(intervals.begin(), intervals.end());
     
        // same thing, we use a greedy method.
        int curr = 0; int max_reach = intervals[0][1];
        int prev_start = intervals[0][0];
        // curr will be index of intervals
        for (; curr < intervals.size(); curr += 1) {
            // if we have passed the interval, push to res
            if (intervals[curr][0] > max_reach) { 
                res.push_back({prev_start, max_reach});
                // update counters
                prev_start = intervals[curr][0];
                max_reach = intervals[curr][1];
            }
            // update max reach and continue
            else {
                max_reach = max(max_reach, intervals[curr][1]);
            }
        }
        // handle last instance
         res.push_back({prev_start, max_reach});
        return res;
    }
};
