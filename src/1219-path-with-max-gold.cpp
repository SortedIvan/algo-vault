class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> seen;
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for (int i = 0; i < grid.size(); ++i) {
            vector<int> row;
            for (int k = 0; k < grid[i].size(); ++k) {
                row.push_back(0);
            }
            seen.push_back(row);
        }

        int maxSum = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (grid[i][k] > 0) {
                    seen[i][k] = 1;
                    maxSum = std::max(grid[i][k], maxSum);
                    getTheGold(maxSum, grid[i][k], seen, grid, i, k, directions);
                }
            }
        }
        
        return maxSum;
    }

    void getTheGold(int& maxSum, int currentSum, vector<vector<int>>& seen, vector<vector<int>>& grid, int x, int y, vector<pair<int,int>>& directions) {
        bool moveWasMade = false;
        for (auto dir : directions) {
            int newX = dir.first + x;
            int newY = dir.second + y;

            if (newX >= 0 && newX < grid.size() && newY >=0 && newY < grid[x].size()) {
                if (!seen[newX][newY] && grid[newX][newY] > 0) {
                    seen[newX][newY] = 1;
                    moveWasMade = true;
                    getTheGold(maxSum, currentSum + grid[newX][newY], seen, grid, newX, newY, directions);
                }
            }
        }

        seen[x][y] = 0;

        if (!moveWasMade) {
            maxSum = std::max(maxSum, currentSum);
        }

    }
};
