class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        // can we do this in place i.e just modify matrix with constant memory?
        // yes, we can

        unordered_map<int, int> colCache;

        for (int i = 0; i < matrix.size(); ++i) { // for every row
            for (int k = 0; k < matrix[i].size(); ++k) {
                if (matrix[i][k] == -1) {
                    if (colCache.find(k) != colCache.end()) {
                        matrix[i][k] = colCache[k];
                    }
                    else {
                        int largest = findLargestElementInColumn(k, matrix);
                        colCache.insert({k, largest});
                        matrix[i][k] = largest;
                    }
                }  
            }
        }

        return matrix;
    }

    int findLargestElementInColumn(int col, const vector<vector<int>>& matrix) {
        int largest = -1;

        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][col] > largest) {
                largest = matrix[i][col];
            }
        }
        
        return largest;
    }
};
