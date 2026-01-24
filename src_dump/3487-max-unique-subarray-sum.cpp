class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int currSum = 0;
        int biggestNegativeNum = std::numeric_limits<int>::min();

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) {
                biggestNegativeNum = std::max(biggestNegativeNum, nums[i]);
                continue;
            }

            if (seen.find(nums[i]) != seen.end()) {
                continue;
            }

            seen.insert(nums[i]);
            currSum += nums[i];
        }

        if (currSum == 0) {
            return biggestNegativeNum;
        }

        return currSum;
    }
};
