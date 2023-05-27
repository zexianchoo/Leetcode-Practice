/* Created on 26 05 2023 - 10:03PM */ 
class Solution {
public:
    int findComplement(int num) {
        // 10
        // 01
        int res = 0;
        int counter = 0;
        // if this digit is 1, shift res.
        while (num > 0) {
            // if the digit is 0, then 
            if ((num & 1)) {
                res += pow(2, counter);
            }
            counter++;
            num >>= 1;
        }
        return res;
    }
};
