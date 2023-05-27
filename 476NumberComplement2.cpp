/* Created on 26 05 2023 - 10:07PM */ 
class Solution {
public:
    int findComplement(int num) {
        // sliding mask.
        unsigned mask = ~0;
        
        // get mask size (that covers none of the numbers)
        while(num & mask) {
            mask <<= 1;
        }
        // invert the mask, and you get 1s where all the numbers are.
        // subsequently, we will xor to get the complement
        return ~mask ^ num;
    }
};
