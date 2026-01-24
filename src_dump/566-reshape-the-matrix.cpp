class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // idea: initialize the new matrix with the desired new size (r x c)
        // have two pointers: one for the old matrix, one for the new matrix 
        // start traversing them & fill it out

        int size = mat[0].size() * mat.size();
        if (size !=  r * c) {
            return mat;
        }

        vector<vector<int>> result;
        pair<int,int> resPointer = {0,0};

        for (int i = 0; i < r; ++i) {
            vector<int> row;
            for (int k = 0; k < c; ++k) {
                row.push_back(0);
            }
            result.push_back(row);
        }

        for (int i = 0; i < mat.size(); ++i) {
            for (int k = 0; k < mat[i].size(); ++k) {
                addNextNrIntoMatrix(result, resPointer, mat[i][k]);
            }
        }    

        return result;
    }

    void addNextNrIntoMatrix(vector<vector<int>>& result, pair<int,int>& resPointer, int nr) {
        if (resPointer.second == result[0].size()) {
            resPointer.first++; 
            resPointer.second = 0;
        }

        if (resPointer.first == result.size()) {
            return;
        }

        result[resPointer.first][resPointer.second] = nr;
        resPointer.second++;
    }
};
