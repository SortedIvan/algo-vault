class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> cols;
        unordered_map<string, int> rows;
        int totalNumEqual = 0;

        for (int i = 0; i < grid.size(); ++i) {
            string col;
            string row;
            for (int k = 0; k < grid[i].size(); ++k) {
                col = col + std::to_string(grid[k][i]);
                row = row + std::to_string(grid[i][k]);

                col += "-";
                row += "-";
            }
            cols[col]++;
            rows[row]++;
        }

        for (auto entry : rows) {
            if (cols.find(entry.first) != cols.end()) {
                totalNumEqual += entry.second * cols[entry.first];
            }
        }

        return totalNumEqual;
    }
};
