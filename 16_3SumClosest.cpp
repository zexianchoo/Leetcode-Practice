/* Created on 29 05 2023 - 03:10PM */ 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // makes sense if we sort it stil
        // shouldnt bin search work? im not finding one, but im finding a pair.
        // and the problem is that i cant find the exact number
        // start by sorting the array
        sort(nums.begin(), nums.end());
        if (nums.size() <= 3) {
            return nums[0] + nums[1] + nums[2];
        }
        int left, right;
        int closest = nums[0] + nums[1] + nums[2];
        // fix one number
        for (int i = 0; i < nums.size() - 2; i += 1) {
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // initialize pointers
            left = i + 1;
            right = nums.size() - 1;
            while(right > left) {
                int curr_sum = nums[i] + nums[left] + nums[right];
                // if we are better than actual  save this
                if (abs(target - curr_sum) < abs(target - closest)) {
                    closest = curr_sum;
                }
                // increment left if we need to increase
                if (curr_sum < target) {
                    left += 1;
                }
                else { 
                    right -= 1;
                }
            }
        }
        return closest;
    }
};
