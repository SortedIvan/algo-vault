class Solution {
public:
    long long coloredCells(int n) {
        long long total = 0;

        if (n == 1) {
            return 1;
        }

        for (int i = 1; i < n + 1; ++i) {
            if (i == 1) {
                total = 1;
                continue;
            }

            total = 4 * (i - 1) + total;
        }

        return total;
    }
};
