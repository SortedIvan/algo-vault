class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // idea: iterate the array column by column and wipe out anything where
        // it isnt element[i] >= element[i+1]

        int colsToDelete = 0;
        for (int col = 0; col < strs[0].size(); ++col) {
            for (int row = 0; row < strs.size() - 1; ++row) {
                if (strs[row][col] > strs[row + 1][col]) {
                    // delete this col
                    colsToDelete++;
                    break;
                }
            }
        }

        return colsToDelete;
    }
};
