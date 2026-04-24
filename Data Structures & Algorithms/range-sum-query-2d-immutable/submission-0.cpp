class NumMatrix {
   private:
    vector<vector<int>> prefixMatrix;

   public:
    NumMatrix(vector<vector<int>>& matrix)
        : prefixMatrix(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)) {
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                prefixMatrix[r + 1][c + 1] = matrix[r][c] + prefixMatrix[r][c + 1] +
                                             prefixMatrix[r + 1][c] - prefixMatrix[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 += 1, col1 += 1, row2 += 1, col2 += 1;

        return prefixMatrix[row2][col2] - prefixMatrix[row1 - 1][col2] -
               prefixMatrix[row2][col1 - 1] + prefixMatrix[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */