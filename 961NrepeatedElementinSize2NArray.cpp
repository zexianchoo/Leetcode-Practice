/* Created on 01 10 2023 - 11:43PM */ 
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int total_size = nums.size();
        unordered_map<int, int> counts;
        int biggest = nums[0], second_biggest = nums[0];
        for (unsigned int i = 0; i < nums.size(); i += 1){
            
            // increment
            counts[nums[i]]++;
            
            if (counts[nums[i]] > counts[biggest]) { biggest = nums[i]; }
            else if (counts[nums[i]] > counts[second_biggest]) { second_biggest = nums[i]; }
            // check if impossible for anything to be bigger
            int nums_left = total_size - i;
            if (nums_left < (biggest - second_biggest)) { return biggest; }
        }
        return biggest; 
    }
};
