class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int totalSum = calculateTotalSum(grid.size());
        std::unordered_map<int,int> numMap;
        int numberWhichIsDoubled = 0;
        int missingNum = 0;
        int accumulativeSum = 0;


        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                int num = grid[i][k];

                if (numMap.find(num) != numMap.end()) {
                    numberWhichIsDoubled = num;
                }
                else {
                    numMap.insert({num, 1});
                }

                accumulativeSum += num;
            }
        }

        missingNum = totalSum - (accumulativeSum - numberWhichIsDoubled);
        return vector<int>{numberWhichIsDoubled, missingNum};
    }

    int calculateTotalSum(int size) {
        int sizeSqr = size * size;
        return (sizeSqr * (sizeSqr + 1)) / 2;
    }
};
