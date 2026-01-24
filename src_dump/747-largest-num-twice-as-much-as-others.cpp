class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largestNum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[largestNum] < nums[i]) {
                largestNum = i;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (largestNum == i) {
                continue;
            }

            if (nums[i] * 2 > nums[largestNum]) {
                return -1;
            }
        }

        return largestNum;
    }
};
