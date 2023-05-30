/* Created on 28 05 2023 - 09:11PM */ 
class Solution {
public:
    void pushVec(vector<vector<int>>& res, int i, int j, int k) {
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back(j);
        tmp.push_back(k);
        res.push_back(tmp);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
      // 2 pointer approach
      sort(nums.begin(), nums.end());
      vector<vector<int>> res;
      // fix one number
      for(int i = 0; i < nums.size(); i += 1) {
          if (nums[0] > 0) break;
          if (i > 0 && nums[i] == nums[i - 1]) {
              continue; 
          }
          int left = i + 1, right = nums.size() - 1;
          // iterate through remaining array
          while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            // if the sum is above 0, we need to decrease the value, which means we decrement the riht
            if (sum > 0) {
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            // if found target
            else {
                pushVec(res, nums[left], nums[right], nums[i]);
                                    int last_low_occurence = nums[left] , last_high_occurence = nums[right];  //Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
                    while(left < right && nums[left] == last_low_occurence){   // Update the low and high with last occurences of low and high.
                        left++;
                    }
                    while(left < right && nums[right] == last_high_occurence){
                        right--;
                    }
            }
          }
      }  
      return res;
    }
};
