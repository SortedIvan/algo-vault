class Solution {
public:
    vector<string> createGrid(int m, int n) {
        std::vector<string> resultGrid;

        // Base cases
        if (m == 1) {
            std::string row;
            for (int i = 0; i < n; ++i) {
                row += ".";
            }
            resultGrid.push_back(row);
            return resultGrid;
        }
        else if (n == 1) {
            for (int i = 0; i < m; ++i) {
                resultGrid.push_back(".");
            }
            return resultGrid;
        }
        else if (m == 1 && n == 1) {
            return {"."};
        }

        std::string firstRow;

        for (int i = 0; i < n; ++i) {
            firstRow += '.';
        }

        resultGrid.push_back(firstRow);

        for (int i = 1; i < m; ++i) {
            std::string row;

            for (int k = 0; k < n; ++k) {
                // last col, insert a . instead
                if (k == n - 1) {
                    row += '.';
                }
                else {
                    row += '#';
                }
            }

            resultGrid.push_back(row);
        }

        return resultGrid;
    }
};
