class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // for every column, start a diagonal search

        for (int i = 0; i < matrix[0].size(); ++i) {
            bool result = traverseDiagonalAndCheckIfEqual(matrix, i);

            if (!result) {
                return false;
            }
        }

        return true;
    }

    bool traverseDiagonalAndCheckIfEqual(vector<vector<int>>& matrix, int column) {
        for (int k = 0; k < matrix.size(); ++k) {
            int elementToCompareTo = matrix[k][column];
            
            for (int i = k + 1; i < matrix.size(); ++i) {
                int new_x = i; 
                int new_y = column + (i - k); 

                if (new_x >= matrix.size() || new_x < 0 || new_y >= matrix[0].size() ||
                    new_y < 0) {
                    break;
                }

                if (elementToCompareTo != matrix[new_x][new_y]) {
                    return false;
                }
            }    

        }

        return true;
    }
};
