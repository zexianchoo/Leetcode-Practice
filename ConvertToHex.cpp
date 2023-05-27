/* Created on 25 05 2023 - 10:08PM */ 
class Solution {
public:
    string toHex(int num) {
        if (num == 0) { return "0"; }
        
        // casts to twos complement:
        unsigned n = num;
        string res;
        const string hex_ref = "0123456789abcdef";
        while (n > 0) {
            res = hex_ref[n & 0xf] + res;
            // bitshift 4.
            n >>= 4;
        }
        return res;
    }
};
