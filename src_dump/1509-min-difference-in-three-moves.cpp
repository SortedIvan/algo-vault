class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }

        int minDiff = std::numeric_limits<int>::max();

        std::sort(nums.begin(), nums.end());

        calculateDifference(nums,1, nums.size() - 3, minDiff); // one element from front, two from back
        calculateDifference(nums,2, nums.size() - 2, minDiff); // two from front, one from back
        calculateDifference(nums, 3, nums.size() - 1, minDiff); 
        calculateDifference(nums, 0, nums.size() - 4, minDiff); 

        return minDiff;
    }

    void calculateDifference(vector<int>& nums, int indexOne, int indexTwo, int& currMinDiff) {
        currMinDiff = std::min(currMinDiff, nums[indexTwo] - nums[indexOne]);
    }
};
