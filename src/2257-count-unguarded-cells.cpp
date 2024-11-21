class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix;  
        int unguardedCells = m * n;      
        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < m; ++i) {
            vector<int> row;
            for (int k = 0; k < n; ++k) {
                row.push_back(0);
            }
            matrix.push_back(row);
        }

        // 0 for any cell, 1 for guard, 2 for wall
        for (int i = 0; i < guards.size(); ++i) {
            matrix[guards[i][0]][guards[i][1]] = 1;
            unguardedCells--;
        }

        for (int i = 0; i < walls.size(); ++i) {
            matrix[walls[i][0]][walls[i][1]] = 2;
            unguardedCells--;
        }

        std::cout << unguardedCells << std::endl;

        // for guarded cells, mark them with 3 after traversing
        for (int i = 0; i < matrix.size(); ++i) {
            for (int k = 0; k < matrix[i].size(); ++k) {
                if (matrix[i][k] == 1) {
                    markGuardedCells(unguardedCells, matrix, i, k, directions);
                }
            }
        }

        return unguardedCells;
    }

void markGuardedCells(int& unguardedCells, vector<vector<int>>& matrix, const int& x, const int& y, vector<pair<int, int>>& directions) {
    for (int i = 0; i < directions.size(); ++i) {
        pair<int, int> dir = directions[i];
        int newX = x + dir.first;
        int newY = y + dir.second;

        while (true) {
            if (newX < 0 || newX >= matrix.size() || newY < 0 || newY >= matrix[x].size()) {
                break; 
            }

            if (matrix[newX][newY] == 2) {
                break; 
            }

            if (matrix[newX][newY] == 0) {
                unguardedCells--; 
                matrix[newX][newY] = 3; 
            }

            newX = newX + dir.first;
            newY = newY + dir.second;
        }
    }
}

};
