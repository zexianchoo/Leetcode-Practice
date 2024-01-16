/* Created on 01 12 2023 - 00:16AM */ 
class Solution {
public:
    bool checkRecord(string s) {
        int buffer_1 = 0;
        int buffer_2 = 0;
        int buffer_3 = 0;
        int absent_count = 0;
        for (unsigned int i = 0; i < s.size(); i += 1) {
            buffer_3 = buffer_2;
            buffer_2 = buffer_1;
            buffer_1 = 0;
            if (s[i] == 'A') { absent_count += 1; }
            else if (s[i] == 'L') {
                buffer_1 = 1;
            }
            if (buffer_1 == 1 && buffer_2 == 1 && buffer_3 == 1) { return false;}
        }
        return absent_count < 2;
    }
};
