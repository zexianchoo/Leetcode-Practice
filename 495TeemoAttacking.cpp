/* Created on 27 05 2023 - 04:46PM */ 
lass Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        // iterate through and check next + this time
        for (unsigned int i = 0; i < timeSeries.size() - 1; i += 1) {
            int currtime = timeSeries[i];
            int nexttime = timeSeries[i + 1];
            // update res, depending on whether the difference is less than duration
            int diff = nexttime - currtime;
            if (diff < duration) { res += diff; }
            else { res += duration; }
        }
    
        // last hit will have full duration
        res += duration;
        return res;
    }
};
