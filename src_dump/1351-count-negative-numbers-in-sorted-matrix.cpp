class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int k = grid[i].size() - 1; k >= 0; k--) {
                if (grid[i][k] >= 0) {
                    break;
                }

                count++;
            }
        }

        return count;
    }
};
