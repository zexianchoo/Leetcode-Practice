/* Created on 02 06 2023 - 06:55PM */ 
class Solution {
public:
    int toInt(string in) {
        int res = 0;
        int curr_power = 1;
        while(in.empty()) {
            int last = in[in.size() - 1] - '0';
            in.pop_back();
            res += last * curr_power;
            curr_power *= 10;
        }
        return res;
    }
    string multiply(string num1, string num2) {
        if (num1 == "" && num2 == "") { return "0"; }
        int carry = 0;
        std::cout << toInt(num1);
        return to_string(toInt(num1) * toInt(num2));
    }
};
