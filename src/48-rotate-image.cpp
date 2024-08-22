class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transposeInPlace(matrix);
        reverseEachRow(matrix);
    }
    
    void transposeInPlace(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int k = 0; k < matrix[i].size(); ++k) {                
                if (i < k) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[k][i];
                    matrix[k][i] = temp;
                }
            }
        }
    }
    
    void reverseEachRow(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            int leftPointer = 0;
            int rightPointer = matrix[i].size() - 1;

            while (leftPointer < rightPointer) {
                int temp = matrix[i][leftPointer];
                matrix[i][leftPointer] = matrix[i][rightPointer];
                matrix[i][rightPointer] = temp;
                leftPointer++;
                rightPointer--;
            }
        }
    }
};
