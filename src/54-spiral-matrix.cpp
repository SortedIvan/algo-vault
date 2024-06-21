class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        vector<vector<int>> seen;

        if (matrix.size() == 0) {
            return result;
        }

        for (int i = 0; i < matrix.size(); ++i) {

            vector<int> row;

            for (int j = 0; j < matrix[i].size(); ++j) {
                row.push_back(0);
            }

            seen.push_back(row);
        }

        seen[0][0] = 1;
        result.push_back(matrix[0][0]); 
        int x = 0;
        int y = 0;
        int direction = 0;
        int switchCounter = 0;
        traverseMatrix(matrix, seen, result, x,y,direction,switchCounter);

        return result;
    }

    // 0 right
    // 1 down
    // 2 left
    // 3 up
    void traverseMatrix(vector<vector<int>>& matrix, vector<vector<int>>& seen, vector<int>& result, int& x, int& y, int& direction, int& switchCounter) {
        
        if (switchCounter > 1) {
            return;
        }
        
        switch(direction) {
            case 0:
                if (y + 1 < matrix[x].size() && !seen[x][y+1]) {
                    result.push_back(matrix[x][y+1]);
                    seen[x][y+1] = 1;
                    switchCounter = 0;
                    y++;
                    traverseMatrix(matrix,seen,result,x,y,direction, switchCounter);
                } else {
                    switchCounter++;
                    direction = 1;
                    traverseMatrix(matrix,seen,result,x,y,direction, switchCounter);
                }
            break;
            case 1:
                if (x + 1 < matrix.size() && !seen[x+1][y]) {
                    result.push_back(matrix[x+1][y]);
                    seen[x+1][y] = 1;
                    switchCounter = 0;
                    x++;
                    traverseMatrix(matrix,seen,result,x,y,direction, switchCounter);
                } else {
                    switchCounter++;
                    direction = 2;
                    traverseMatrix(matrix,seen,result,x,y,direction, switchCounter);
                }
            break;
            case 2:
                if (y - 1 >= 0 && !seen[x][y-1]) {
                    result.push_back(matrix[x][y-1]);
                    seen[x][y-1] = 1;
                    switchCounter = 0;
                    y--;
                    traverseMatrix(matrix,seen,result,x,y,direction, switchCounter);
                } else {
                    switchCounter++;
                    direction = 3;
                    traverseMatrix(matrix,seen,result,x,y,direction, switchCounter);
                }
            break;
            case 3:
                if (x - 1 >= 0 && !seen[x-1][y]) {
                    result.push_back(matrix[x-1][y]);
                    seen[x-1][y] = 1;
                    switchCounter = 0;
                    x--;
                    traverseMatrix(matrix,seen,result,x,y,direction, switchCounter);
                } else { 
                    switchCounter++;
                    direction = 0;
                    traverseMatrix(matrix,seen,result,x,y,direction, switchCounter);
                }
        }

    }
};
