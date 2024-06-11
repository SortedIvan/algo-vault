class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int leftPointer =  0;
        int rightPointer = nums.size() - 1;

        int largest = std::numeric_limits<int>::lowest();

        while (leftPointer < rightPointer)
        {
            if (nums[leftPointer] > 0)
            {
                return -1;
            }            
            
            if (nums[rightPointer] < 0)
            {
                return -1;
            }

            if (std::abs(nums[leftPointer]) == nums[rightPointer])
            {
                return nums[rightPointer];
            }

            if (std::abs(nums[leftPointer]) < nums[rightPointer])
            {
                rightPointer--;
                continue;
            }

            if (std::abs(nums[leftPointer]) > nums[rightPointer])
            {
                leftPointer++;
                continue;
            }
        }

        return -1;

    }
};
