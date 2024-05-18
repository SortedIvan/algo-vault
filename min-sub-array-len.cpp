class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int currSum = 0;
        int minSize = std::numeric_limits<int>::max();

        while (right < nums.size()) {
            currSum += nums[right];
            right++;
        
            while (currSum >= target) {
                minSize = std::min(minSize, right - left);
                currSum -= nums[left];
                left++;
            }
        }

        if (minSize == std::numeric_limits<int>::max())
        {
            return 0;
        }

        return minSize;
    }
};
