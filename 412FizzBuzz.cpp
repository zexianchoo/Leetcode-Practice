/* Created on 26 05 2023 - 07:56AM */ 
class Solution {
public:
    // makes strong at location
    string makeString(int n) {
        if (n % 3 == 0 && n % 5 == 0) {
            return "FizzBuzz";
        }
        else if (n % 3 == 0) { return "Fizz"; }
        else if (n % 5 == 0) { return "Buzz"; }
        
        return to_string(n);
    }
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        if (n == 0) { return res; }
        for (int i = 1; i <= n; i += 1) {
            res.push_back(makeString(i));
        }
        return res;
    }
};
