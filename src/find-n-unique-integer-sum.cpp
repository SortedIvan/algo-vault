class Solution {
public:
    vector<int> sumZero(int n) {
        // n = 100

        if (n == 1) {
            return std::vector<int>{0};
        }

        std::vector<int> result;
        int totalSum = 0;

        for (int i = 1; i < n; ++i) {
            totalSum += (n+i);
            result.push_back(n + i);
        }

        result.push_back(-totalSum);

        return result;
    }
};
