class Solution {
public:
    int findMidPoint(std::vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        int left = 0;
        int right = nums.size() - 1;
        int balancePoint = 0;

        if (nums[0] > nums[1]) {
            balancePoint = nums[0];
        }

        if (nums[right] > nums[0]) {
            balancePoint = nums[right];
        }

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                balancePoint = nums[mid];
                break;
            }

            if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) {
                if (nums[mid - 1] > nums[mid + 1]) {
                    balancePoint = nums[mid - 1];
                }
                else {
                    balancePoint = nums[mid + 1];
                }
                break;
            }

            if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
                if (nums[0] > nums[nums.size() - 1]) {
                    if (nums[mid + 1] > nums[0]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return balancePoint;
    }
};
