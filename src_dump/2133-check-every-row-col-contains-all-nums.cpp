class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        vector<unordered_set<int>> rows;
        vector<unordered_set<int>> cols;

        unordered_set<int> setWithAllNums;

        for (int i = 1; i < matrix.size() + 1; ++i) {
            setWithAllNums.insert(i);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            rows.push_back(setWithAllNums);
            cols.push_back(setWithAllNums);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int k = 0; k < matrix[i].size(); ++k) {
                rows[i].erase(matrix[i][k]);
                cols[k].erase(matrix[i][k]);
            }
        }

        for (int i = 0; i < rows.size(); ++i) {
            if (!rows[i].empty() || !cols[i].empty()) {
                return false;
            }
        }

        return true;
    }
};
