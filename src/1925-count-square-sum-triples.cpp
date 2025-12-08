class Solution {
public:
    int countTriples(int n) {
        int count = 0;

        unordered_map<int, int> squared;

        for (int i = 1; i <= n; ++i) {
            squared.insert({i * i, i});
        }

        for (int i = 1; i < n; ++i) {
            for (int k = 1; k < n; ++k) {
                int sum = i * i + k * k;

                if (squared.find(sum) != squared.end()) {
                    if (squared[sum] <= n) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
