class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }

        if (nums[1] < nums[0])
        {
            // handle leftmost edge case
            return 0;
        }

        if (nums[nums.size() - 1] > nums[nums.size() - 2])
        {
            // handle rightmost edge case
            return nums.size() - 1;
        }

        int result = binarySearch(1, nums.size() - 1, nums);

        return result;
    }

    int binarySearch(int left, int right, std::vector<int>& nums)
    {
        int mid = (left + right) / 2;

        if (left > right)
        {
            return -1;
        }

        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
        {
            return mid;
        }

        if (nums[mid] < nums[mid + 1])
        {
            if (nums[mid - 1] > nums[mid + 1])
            {
                return binarySearch(left, right - 1, nums);
            }

            return binarySearch(left + 1, right, nums);
        }

        if (nums[mid] < nums[mid - 1])
        {
            if (nums[mid - 1] < nums[mid + 1])
            {
                return binarySearch(left + 1, right, nums);
            }

            return binarySearch(left, right - 1, nums);
        }

        return -1;
    }
};
