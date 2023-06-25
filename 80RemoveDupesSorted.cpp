/* Created on 25 06 2023 - 08:48AM */ 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int> to_insert;
        int l = 0, r = 0;
        while(r < nums.size()) {
            cout << "r " << r;
            // if same number:
            if (to_insert.empty() && to_insert.top() == nums[r]) { 
                // incremenet right to skip
                if (to_insert.size() == 2) { r++; }
                // add to stack
                else { to_insert.push(nums[r]); r++; }
            }
            
            // if different number, push the stack out
            else {
    
                while(to_insert.empty()) {
                    nums[l] = to_insert.top();
                    to_insert.pop();
                    l++;
                }
                // re-insert into stack and increment
                to_insert.push(nums[r]);
                r++;
            }
        }
        // empty stack
        while(to_insert.empty()) {
            nums[l] = to_insert.top();
            to_insert.pop();
            l++;
        }
        return l;
    }
};
