/* Created on 05 06 2023 - 01:09PM */ 
class Solution {
public:
    // best algo would be to rotate one element at a time, ring by ring.
    void rotate(vector<vector<int>>& matrix) {
        int a = 0, b = matrix.size() - 1;
        while (a < b) {
            for (int i = 0; i < (b - a); i += 1) {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }
            a += 1; b -= 1;
        }
    }
};
