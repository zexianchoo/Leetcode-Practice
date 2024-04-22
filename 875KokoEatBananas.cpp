/* Created on 01 04 2024 - 11:42PM */ 
class Solution {
public:
    long countTotalHours(const vector<int>& piles, int b_per_h) {
        long res = 0;
        for (int i = 0; i < piles.size(); i += 1){
            res += piles[i] / b_per_h;
            if (piles[i] % b_per_h) { res += 1; }
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // get max and min of vector
        int left = 1;
        int right = INT_MIN;
        for (int i = 0; i < piles.size(); i += 1) {
            left = min(left, piles[i]);
            right = max(right, piles[i]);
        }        
        int mid;
        int result = right;
        while (left <= right) {
            mid = (right + left) / 2;
            long total_hours = countTotalHours(piles, mid);
            
            // if we are eating too slow, increase speed
            if (total_hours > h) {
                left = mid + 1;
            }
            else { 
                result = min(result, mid); 
                right = mid - 1; 
            }
        }
        return result;
    }
};
