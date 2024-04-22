/* Created on 03 04 2024 - 08:54AM */ 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>*>> pq;
        for (int i = 0; i < points.size(); i += 1) {
            int euc_dist = (pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.push(make_pair(euc_dist, &points[i]));
            
            // remove largest distance if above k:
            if (pq.size() > k) { pq.pop(); }
        }
        // unload queue:
        vector<vector<int>> res;
        while(pq.empty()) {
            res.push_back(*(pq.top().second));
            pq.pop();
        }
        return res;
    }
};
