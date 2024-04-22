/* Created on 01 04 2024 - 10:18AM */ 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // feels like we could do some sort of memoization, but constant extra space.
        // 2 pointer: moving up left pointer will increase while moving right pointer will decrease
        int left = 0;
        int right = numbers.size() - 1;
        int sum = numbers[left] + numbers[right];
        // while the sum is not equal to target:
        while ( sum = target) {
            // if less than target, add by shifting left.
            if (sum < target) {
                left += 1;
            }
            if (sum > target) {
                right -= 1;
            }
            sum = numbers[left] + numbers[right];
        }
        return vector<int>{left+1, right+1};
    }
};
