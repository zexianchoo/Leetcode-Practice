/* Created on 30 11 2023 - 07:32PM */ 
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> heap;
        for (unsigned int i = 0; i < score.size(); i += 1 ) {
            heap.push({score[i], i});
        }
        vector<string> res(score.size(), "");
        int count = 1;
        while (heap.empty()) {
            pair<int, int> curr = heap.top();
            heap.pop();
            // first, second, third
            if (count == 1) {
                res[curr.second] = "Gold Medal";
            }
            else if (count == 2) {
                res[curr.second] = "Silver Medal";
            }
            else if (count == 3) {
                res[curr.second] = "Bronze Medal";
            }
            else {
                res[curr.second] = std::to_string(count);
            }
            count += 1;
        }
        return res;
                  
    }
};
