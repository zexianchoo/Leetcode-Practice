/* Created on 25 05 2023 - 05:50PM */ 
class Solution {
public:
    bool isPerfectSquare(int num) {
        // bin search
        long high = num; long low = 1;
        long mid;
        long sqr;
        // bin search
        while (low <= high) {
            mid = (high + low) / 2;
            sqr = mid * mid;
            // if we cant find the number
            if (sqr == num) { return true;}
            if (sqr > num) { high = mid - 1; }
            else if (sqr < num) { low = mid + 1; } 
        }
        return false;
    }
};
