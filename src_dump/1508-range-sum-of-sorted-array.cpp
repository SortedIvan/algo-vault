class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> subarraySums;
        int resPointer = 0;
        int subPointer = 0;
        int currSum = 0;

        while (resPointer < nums.size()) {
            currSum += nums[subPointer];
            subarraySums.push_back(currSum);
            subPointer++;

            if (subPointer == nums.size()) {
                resPointer++;
                subPointer = resPointer;
                currSum = 0;
            }
        }

        std::sort(subarraySums.begin(), subarraySums.end());

        long resultSum = 0;
        int mod = 1000000007;

        for (int i = left - 1; i < right; ++i) {
            resultSum += subarraySums[i];
        }

        if (resultSum > 2147483647) {
            return resultSum % mod;
        }

        return resultSum;
    }
};
