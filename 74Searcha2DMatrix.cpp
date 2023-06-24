/* Created on 24 06 2023 - 06:23PM */ 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // edge case
// if matrix have 0 rows or 0 colums
        if(n == 0 || m == 0)
            return false;
        // bin search on row first, then bin search along the columns?
        int l = 0;
        int r = (n * m) - 1;
        int mid;
        // treat the entire array as a sorted array
        while(l <= r) {
            mid = l + (r - l) / 2;
            int col = mid % m;
            int row = mid / m;
            if (matrix[row][col] == target) { return true; }
            else if (matrix[row][col] < target) { l = mid + 1; }
            else { r = mid - 1; }
        }
        return false;
    }
};
