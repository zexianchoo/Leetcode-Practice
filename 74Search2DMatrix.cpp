/* Created on 01 04 2024 - 10:06PM */ 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // bin search for row:
        int l = 0;
        int r = matrix.size() - 1;
        int mid = 0;
        while (l < r) {
            mid = (r - l) / 2 + l;
            // for each iteration, check if target is greater than left, 
            // and less than right
            if (matrix[mid].back() < target) { l = mid + 1; }
            else if( matrix[mid][0] > target) {
                r = mid - 1;
            }
            else { l = mid; break; }
        }
        // bin search within row:
        int row_num = l;
        cout << row_num;
        l = 0; r = matrix[row_num].size() - 1;
        while (l <= r) {
            mid = (r - l) / 2 + l;
            // for each iteration, check if target is greater than left, 
            // and less than right
            if (matrix[row_num][mid] == target) { return true; }
            else if( matrix[row_num][mid] > target) {
                r = mid - 1;
            }
            else { l = mid + 1; }
        }
        return false;
    }
};
