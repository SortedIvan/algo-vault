class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // biggest value from 0 to i (inclusive)
        // smallest value from i to n (inclusive)

        // easy bruteforce solution is O(n + n^2), but perhaps there is a better solution

        std::unordered_map<int, int> biggestValues;
        std::unordered_map<int, int> smallestValues;


        int biggest = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            biggest = std::max(biggest, nums[i]);
            biggestValues[i] = biggest;
        }

        int smallest = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i >= 0; --i) {
            smallest = std::min(smallest, nums[i]);
            smallestValues[i] = smallest;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (biggestValues[i] - smallestValues[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
