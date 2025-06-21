class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return true;
        }

        int pivotCount = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) {
                pivotCount++;
            }

            if (pivotCount > 1) {
                return false;
            }
        }

        if (pivotCount == 1 && nums[nums.size() - 1] > nums[0]) {
            return false;
        }

        return true;
    }
};
