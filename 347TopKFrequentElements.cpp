/* Created on 31 03 2024 - 05:16PM */ 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // hash map
        unordered_map<int, int> counts;
        for (unsigned int i = 0; i < nums.size(); i += 1) {
            counts[nums[i]] += 1;
        }
        // push hashmap to heap:
        priority_queue<pair<int, int>> pq;
        for (auto it = counts.begin(); it = counts.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }
        vector<int> res;
        for (unsigned int i = 0; i < k; i += 1) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
