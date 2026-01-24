class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> cache(n + 1, -1);
        return helper(n, cache);
    }

    int helper(int n, std::vector<int>& cache) {
        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        if (cache[n] != -1) {
            return cache[n];
        }
 
        cache[n] = helper(n - 1, cache) + helper(n - 2, cache);
        return cache[n];
    }



};
