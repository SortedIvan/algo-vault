class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // Idea: Pre-calculate all column and row prefix sums
        // cut each row and col and calculate

        std::vector<long> rowSums;
        std::vector<long> colSums;

        for (int i = 0; i < grid.size(); ++i) {
            long rowSum = 0;

            for (int k = 0; k < grid[i].size(); ++k) {
                rowSum += grid[i][k];
            }

            rowSums.push_back(rowSum);
        }
        
        for (int i = 0; i < grid[0].size(); ++i) {
            long colSum = 0;

            for (int k = 0; k < grid.size(); ++k) {
                colSum += grid[k][i];
            }

            colSums.push_back(colSum);
        }

        long rowsSumsPrefixSum = 0;
        long colsSumsPrefixSum = 0;

        std::for_each(begin(rowSums), end(rowSums), [&rowsSumsPrefixSum](int x) {
            rowsSumsPrefixSum += x;
        });

        std::for_each(begin(colSums), end(colSums), [&colsSumsPrefixSum](int x) {
            colsSumsPrefixSum += x;
        });

        std::cout << rowsSumsPrefixSum << std::endl;
        std::cout << colsSumsPrefixSum << std::endl;

        long sumToCheckFor = 0;
        // check for rows
        for (int i = 0; i < rowSums.size() - 1; ++i) {  // stop before last
            sumToCheckFor += rowSums[i];

            if (sumToCheckFor == rowsSumsPrefixSum - sumToCheckFor) {
                return true;
            }
        }

        // check for cols
        sumToCheckFor = 0;

        for (int i = 0; i < colSums.size() - 1; ++i) {  // stop before last
            sumToCheckFor += colSums[i];

            if (sumToCheckFor == colsSumsPrefixSum - sumToCheckFor) {
                return true;
            }
        }

        return false;    
    }
};
