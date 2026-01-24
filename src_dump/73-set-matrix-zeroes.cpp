class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rowsAffected;
        set<int> colsAffected;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int k = 0; k < matrix[i].size(); ++k) {
                if (matrix[i][k] == 0) {
                    rowsAffected.insert(i);
                    colsAffected.insert(k);
                }
            }
        }

        for (auto row : rowsAffected) {
            changeRowMatrix(matrix, row);
        }

        for (auto col : colsAffected) {
            changeColMatrix(matrix, col);
        }
    }

    void changeRowMatrix(vector<vector<int>>& matrix, int rowNr) {
        for (int i = 0; i < matrix[rowNr].size(); ++i) {
            matrix[rowNr][i] = 0;
        }
    }

    void changeColMatrix(vector<vector<int>>& matrix, int colNr) {
        for (int i = 0; i < matrix.size(); ++i) {
            matrix[i][colNr] = 0;
        }
    }
};
