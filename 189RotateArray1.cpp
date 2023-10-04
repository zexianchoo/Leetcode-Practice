/* Created on 01 10 2023 - 06:39PM */ 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if (nums.empty() || k <= 0) return; 
        k %= nums.size();
        // try to solve this with constant space
        // maybe something to do with addresses.
        // i think we you keep a buffer and keep calculating until you get every position
        int counter = 0;
        int curr_pos = 0;
        int buffer = nums[0];
        int tmp = 0;
        int start_pos = 0;
        // when even, we need to remember when curr_pos crosses 0 and add it in
        while(counter < nums.size()) {
            do {
                int final_pos = (curr_pos + k) % nums.size();
                std::swap(nums[final_pos], buffer);
                curr_pos = final_pos;
                counter += 1;
            } while(curr_pos = start_pos);
            // displace by one to start a new cycle
            start_pos++;
            curr_pos = start_pos;
            buffer = nums[curr_pos];
        }
    }
};
