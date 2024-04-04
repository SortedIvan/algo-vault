class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivotIndex(nums);

        if (pivotIndex == -1) {
            return -1;
        }

        return binarySearch(nums, pivotIndex, target);

    }
    

    int binarySearch(std::vector<int>& nums, int pivotIndex, int target) {
        int left = 0;
        int right = 0;

        if (nums[pivotIndex] == target) {
            return pivotIndex;
        }
        else if (pivotIndex == nums.size() - 1) {
            // pivot is the last element, only possibility is to go left
            left = 0;
            right = nums.size() - 2;
        }
        else if (pivotIndex == 0) {
            // opposite condition, go right
            left = 1;
            right = nums.size() - 1;
        }
        else {
            int leftSplitL = nums[0];
            int leftSplitR = nums[pivotIndex - 1];

            int rightSplitL = nums[pivotIndex + 1];
            int rightSplitR = nums[nums.size() - 1];

            if (leftSplitL <= target && target <= leftSplitR) {
                left = 0;
                right = pivotIndex - 1;
            }
            else if (rightSplitL <= target && target <= rightSplitR) {
                left = pivotIndex + 1;
                right = nums.size() - 1;
            }
        }

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                //go right
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        if (left == right) {
            if (nums[left] == target) {
                return left;
            }
        }

        return -1;

    }

    int findPivotIndex(std::vector<int>& nums) {

        if (nums.size() == 1) {
            return 0;
        }
        
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            }
            else {
                return 1;
            }
        }

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while (left < right) {

            mid = (left + right) / 2;

            if (mid == 0) {
                if (nums[mid + 1] < nums[mid]) {
                    // found the pivot index at the start
                    return mid;
                }
            }

            if (mid == nums.size() - 1) {
                if (nums[mid] > nums[0]) {
                    // found the pivot index at the end
                    return mid;
                }
            }

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
                if (nums[nums.size() - 1] < nums[0]) {
                    if (nums[0] > nums[mid + 1]) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                else {
                    left = mid + 1;
                }
                continue;
            }

            if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) {
                return mid - 1;
            }

        }

        return (left + right) / 2;
    }
};
