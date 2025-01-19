class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xyArea = 0;
        int xzArea = 0;
        int yzArea = 0;

        for (int i = 0; i < grid.size(); ++i) {
            int rowMax = std::numeric_limits<int>::min();
            for (int k = 0; k < grid[i].size(); ++k) {
                if (grid[i][k] > 0) {
                    xyArea++; 
                }

                rowMax = std::max(grid[i][k], rowMax);
            }

            xzArea += rowMax;
        }

        int colCounter = 0;
        while (colCounter < grid[0].size()) {
            int colMax = std::numeric_limits<int>::min();

            for (int i = 0; i < grid.size(); ++i) {
                colMax = std::max(grid[i][colCounter], colMax);
            }

            colCounter++;
            yzArea += colMax;
        }

        return xyArea + yzArea + xzArea;
    }
};
