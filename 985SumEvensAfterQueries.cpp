/* Created on 01 10 2023 - 08:16PM */ 
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int sum_evens = 0;
        for (auto curr : queries) {
            int val = curr[0];
            int pos = curr[1];
            // initialize sum_evens
            if (res.size() == 0) {
                nums[pos] += val;
                for (int i : nums) {
                    if (i % 2 == 0) { sum_evens += i; }
                }
            }
            else {
                // if currently even, take away from sumeven.
                if (nums[pos] % 2 == 0) { sum_evens -= nums[pos]; }
                nums[pos] += val;
                if (nums[pos] % 2 == 0) { sum_evens += nums[pos]; }
            }
            res.push_back(sum_evens);
        }
        return res;
    }
};
