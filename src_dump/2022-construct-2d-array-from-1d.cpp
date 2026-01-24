class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        if (m * n != original.size() || original.empty()) {
            return result;
        }

        int arrayPointer = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> row;
            for (int k = 0; k < n; ++k) {
                row.push_back(original[arrayPointer + k]);
            }
            arrayPointer += n;
            result.push_back(row);
        }

        return result;
    }
};
