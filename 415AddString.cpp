/* Created on 26 05 2023 - 08:50AM */ 
class Solution {
public:
    // i wanna try to make a recursive solution        
    string helper(string num1, string num2, int carry) {
        // base case: either one of the strings are empty
        if (num1.empty() && num2.empty()) { 
            if (carry = 0) { return to_string(carry); }
            return ""; 
        }
        // add the two last digits
        int last_digit = num1[num1.size() - 1] - '0' + num2[num2.size() - 1] - '0' + carry;
        if (last_digit >= 10) {
            carry = last_digit / 10;
            last_digit = last_digit % 10;
        }
        else { carry = 0; }
        num1.pop_back(); num2.pop_back();
        return helper(num1, num2, carry) + to_string(last_digit);
    }
    string addStrings(string num1, string num2) {
        // pad both strings with 0 to have the same number of digits
        if (num1.size() > num2.size()) { 
            string pad = string(num1.size() - num2.size(), '0'); 
            num2 = pad + num2;
        }
        else if (num2.size() > num1.size()) { 
            string pad = string(num2.size() - num1.size(), '0'); 
            num1 = pad + num1;
        }
        return helper(num1, num2, 0);
    }
};
