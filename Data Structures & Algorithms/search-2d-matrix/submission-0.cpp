class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Treating the 2D matrix as a flat 1D array of size (rows * cols)
        int low = 0;
        int high = (rows * cols) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / cols;
            int col = mid % cols;
            int currentElement = matrix[row][col];

            if (currentElement == target) {
                return true;
            } else if (currentElement > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
