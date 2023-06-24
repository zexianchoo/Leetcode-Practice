/* Created on 23 06 2023 - 10:37PM */ 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // get the first row and columns
        int i = 0;
        int j = 0;
        bool row0 = false;
        bool col0 = false;
        for (; i < matrix.size(); i += 1) { if (matrix[i][j] == 0) { col0 = true; }}
        for (i = 0, j = 0; j < matrix[0].size(); j += 1) { if (matrix[i][j] == 0) { row0 = true; }}
        for (i = 1 ; i < matrix.size(); i += 1) {
            for (j  = 1; j < matrix[0].size(); j += 1) {
                if (matrix[i][j] == 0) {
                    
                    // save the data in first row/col
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // iterate through again
        for (i = 1; i < matrix.size(); i += 1) {
            for (j = 1; j < matrix[0].size(); j += 1 ) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row0) { 
            for (i = 0, j = 0; j < matrix[0].size(); j += 1) {
                matrix[0][j] = 0;
            }
        }
        if (col0) { 
            for (i = 0, j = 0; i < matrix.size(); i += 1) {
                matrix[i][0] = 0;
            }
        }
    }
};
