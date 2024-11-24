class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;

        for (int i = 0; i < n; ++i) {
            vector<int> row;

            for (int k = 0; k < n; ++k) {
                row.push_back(0);
            }

            matrix.push_back(row);
        }        

        vector<pair<int,int>> directions = {{0, 1}, {1,0}, {0,-1},{-1, 0}};
        int dirPointer = 0;
        int number = 1;
        matrix[0][0] = number;
        int attemptCounter = 0;

        if (n == 1) {
            return matrix;
        }

        number++;
        traverseMatrixSpiral(attemptCounter,0,0, matrix, directions, dirPointer, number);
        
        return matrix;
    }

    void traverseMatrixSpiral(int& attemptCounter,int x, int y, vector<vector<int>>& matrix, vector<pair<int, int>>& directions, int& dirPointer, int& number) { 
        if (attemptCounter == 3) {
            return;
        }
        
        pair<int, int> direction = directions[dirPointer];
        int new_x = x + direction.first;
        int new_y = y + direction.second;

        if (new_x < 0 || new_x >= matrix.size() || new_y < 0 || new_y >= matrix[x].size() 
        || (matrix[new_x][new_y] != 0)) {
            dirPointer++;
            if (dirPointer == 4) {
                dirPointer = 0;
            }
            attemptCounter++;
            traverseMatrixSpiral(attemptCounter, x, y, matrix, directions, dirPointer, number);
        }
        else {    
            attemptCounter = 0;
            matrix[new_x][new_y] = number;
            number++;
            traverseMatrixSpiral(attemptCounter, new_x, new_y, matrix, directions, dirPointer, number);
        }
    }
};
