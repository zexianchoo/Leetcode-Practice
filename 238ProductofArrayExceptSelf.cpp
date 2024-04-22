/* Created on 31 03 2024 - 05:43PM */ 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // think about prefix / suffix products.
        vector<int> prefs(nums.size(), 0);
        vector<int> suffs(nums.size(), 0);
        vector<int> res(nums.size(), 0);
        
        // get prefix array
        for (int i = 0; i < nums.size(); i += 1) {
            int flipped = nums.size() - i - 1;
            if (i == 0) {
                prefs[i] = nums[i];
                suffs[flipped] = nums[flipped];
            }
            else {
                prefs[i] = prefs[i - 1] * nums[i];
                suffs[flipped] = suffs[flipped + 1] * nums[flipped];
            }
        }
       
        // for each element in the array, the prod except self is 1 before in pref, 1 after in suf.
        for (unsigned int i = 0; i < res.size(); i += 1) {
            // start edge case
            if (i == 0) {
                res[0] = suffs[1];
            }
            else if (i == res.size() - 1) {
                res[i] = prefs[i - 1];
            }
            else {
                res[i] = prefs[i - 1] * suffs[i + 1];
            }
        }
        return res;
    }
};
