class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        std::vector<int> flattenedGrid;

        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                flattenedGrid.push_back(grid[i][k]);
            }
        }
        int totalSize = flattenedGrid.size();
        k = k % totalSize;

        if (k == 0) {
            return grid;
        }

        rotateVec(flattenedGrid, k);

        int flatArrayIndex = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); k++) {
                grid[i][k] = flattenedGrid[flatArrayIndex++];
            }
        }

        return grid;
    }

    void rotateVec(std::vector<int>& flattenedGrid, int numOfRotations) {
        while (numOfRotations > 0) {
            numOfRotations--;

            int copy = flattenedGrid[0];
            for (int i = 1; i < flattenedGrid.size(); ++i) {
                // [1,2,3,4,5] -> [5,1,2,3,4] -> [4,5,1,2,3]
                int copyTwo = flattenedGrid[i];
                flattenedGrid[i] = copy;
                copy = copyTwo;
            }

            flattenedGrid[0] = copy;
        }
    }
};
