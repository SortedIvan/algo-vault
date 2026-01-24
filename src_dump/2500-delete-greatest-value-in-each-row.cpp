class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        vector<priority_queue<int>> rowMaxHeapElements;
        int totalSum = 0;

        for (int i = 0; i < grid.size(); ++i) {
            std::priority_queue<int> nextRow;
            for (int k = 0; k < grid[i].size(); ++k) {
                nextRow.push(grid[i][k]);
            }
            rowMaxHeapElements.push_back(nextRow);
        }

        for (int i = 0; i < grid[0].size(); ++i) {
            int maxElementToAdd = 0;

            for (int k = 0; k < rowMaxHeapElements.size(); ++k) {
                int nextElementInQueue = rowMaxHeapElements[k].top();
                rowMaxHeapElements[k].pop();
                maxElementToAdd = std::max(maxElementToAdd, nextElementInQueue);
            }

            totalSum += maxElementToAdd;
        }

        return totalSum;
    }
};
