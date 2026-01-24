class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }

        int result = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            float half = (float)nums[i+1] / 2.0;
            std::cout << half << std::endl;
            if (nums[i] + nums[i+2] == half) {
                result++;
            }
        }

        return result;
    }
};
