/* Created on 05 06 2023 - 10:01AM */ 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        // deepcopy nums
        vector<int> curr = nums;
        do {    
            // store to res
            res.push_back(curr);
            
            // permute.
            // 1. find first decreasing pivot 
            unsigned pivot = curr.size() - 1;
            while(pivot > 0 && curr[pivot - 1] >= curr[pivot]) { pivot--; }
            
            // check if we are at the end, break
            if (pivot <= 0) { break; }
            // 2. find rightmost successor Find rightmost element greater than the pivot
            unsigned succ = curr.size() - 1;
            while(curr[succ] <= curr[pivot - 1]) { succ--; }
            // 3. swap the pivot with successor
            swap(curr[succ], curr[pivot - 1]);
            // 4. reverse everything after pivot.
            unsigned end = curr.size() - 1;
            while(end > pivot) {
                swap(curr[end], curr[pivot]);
                end--; pivot++;
            }
        } while (curr = nums);
        return res;
    }
};
// just trying something out, this didnt work 
