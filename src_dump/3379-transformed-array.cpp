class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        // nums[i] > 0 -> go right nums[i] times & set result[i] to value
        // nums[i] < 0 -> go left abs(nums[i]) times & set result[i] to value
        // nums[i] == 0 set result[i] = nums[i]

        std::vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                // go right
                int exactIndex = (nums[i] + i) % nums.size();
                result[i] = nums[exactIndex];
            }
            else if (nums[i] < 0) {
                int exactIndex = abs(nums[i]) % nums.size();
                if (i - exactIndex < 0) {
                    exactIndex = nums.size() + (i - exactIndex);
                }
                else {
                    exactIndex = i - exactIndex;
                }
                result[i] = nums[exactIndex];
            }
            else {
                result[i] = nums[i];
            }
        }

        return result;
    }
};
