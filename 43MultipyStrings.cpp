/* Created on 04 06 2023 - 07:07PM */ 
class Solution {
public:
    string multiply(string num1, string num2) {
        // pre allocate
        string res = string(num1.size() + num2.size(), '0');
        // reverse iterate through
        for (int i = num1.size() - 1; i >= 0; i -= 1) {
            int carry = 0;
            // iterate through other.
            for (int j = num2.size() - 1; j >= 0; j -= 1) {
                int position = i + j + 1;
                // add together original at pos, multiply and carry
                int multiply = (res[position] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                
                // get carry and modulo
                carry = multiply / 10;
                multiply %= 10;
                // save to res
                res[position] = multiply + '0'; 
            }
            // add carry at end.
            res[i] += carry;
        }
        std::cout << res;
        // remove all zeros
        int idx = 0;
        while(res[idx] == '0' && idx < res.size() - 1) {
            idx++;
        }
        return res.substr(idx, res.size());
    }
};
