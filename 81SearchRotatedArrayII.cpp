/* Created on 25 06 2023 - 07:10PM */ 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1, mid;
        // bin search
        while(left <= right) {
            mid = left + (right - left) / 2;
            cout << left << "," << right << "," << mid << " ";
            // found
            if (nums[mid] == target) { return true; }
            // check if the array is ordered on left and right:
            // if ordered on left
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                    left++; right--;
            }
            else if (nums[left] <= nums[mid]) {
                // since there are duplicates, there could be a chance that the 
                // nums[left] == nums[mid], 
                // but its not ordered e.g. [3 1 2 3 3 3 3])
                // to verify, since it must "wrap around", we know that nums[right] == nums[left] too
                // in that case, we sil continue linear search
                
                // case where this is not wrapping around, and ordered on left.
                if (nums[mid] > target && target >= nums[left]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            // right half is in order
            else {
                if (nums[mid] < target && target <= nums[right]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
            }
        }
        return false;
    }
};
