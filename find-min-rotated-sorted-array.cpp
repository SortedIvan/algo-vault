class Solution {
public:

int findMin(std::vector<int>& nums) {

    if (nums.size() == 1) {
        return nums[0];
    }

    if (nums.size() == 2) {
        if (nums[0] > nums[1]) {
            return nums[1];
        }
        return nums[0];
    }

    int balancePoint = FindBalancePoint(nums);

    if (balancePoint == 0) {
        return nums[1];
    }

    if (balancePoint == nums.size() - 1) {
        return nums[0];
    }

    return nums[balancePoint + 1];
}

int FindBalancePoint(std::vector<int>& nums) {
    if (nums.size() == 1) {
        return 0;
    }

    int left = 0;
    int right = nums.size() - 1;
    int balancePoint = 0;

    if (nums[0] > nums[1]) {
        balancePoint = 0;
    }

    if (nums[right] > nums[0]) {
        balancePoint = right;
    }

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            balancePoint = mid;
            break;
        }

        if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) {
            if (nums[mid - 1] > nums[mid + 1]) {
                balancePoint = mid - 1;
            }
            else {
                balancePoint = mid + 1;
            }
            break;
        }

        if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
            if (nums[0] > nums[nums.size() - 1]) {
                if (nums[mid + 1] > nums[0]) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
            else {
                left = mid + 1;
            }
        }
    }

    return balancePoint;
}
};
