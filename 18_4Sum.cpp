/* Created on 29 05 2023 - 04:25PM */ 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // have to settle for O(n^3)
        vector<vector<int>> res;
        if (nums.size() < 4) { return res; }
        sort(nums.begin(), nums.end());
        // fix 1 
        for (int i = 0; i < nums.size() - 3; i += 1) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // fix 2
            for (int j = i + 1; j < nums.size() - 2; j += 1) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
                int left = j + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[left];
                    sum += nums[right];
                    if (sum > target) {
                        right -= 1;
                    }
                    else if (sum < target) { left += 1; }
                    else { 
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // prevent dupes
                        do{ left++; } while(nums[left] == nums[left - 1] && left < right);
                        do{ right--; } while(nums[right] == nums[right + 1] && left < right);
                    }
                }
            }
        }
        return res;
    }
};
