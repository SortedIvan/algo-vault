class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        std::unordered_map<int, int> counter;
        int n = nums.size() / 2;

        for (int i = 0; i < nums.size(); ++i) {
            counter[nums[i]]++;

            if (counter[nums[i]] == n) {
                return nums[i];
            }
        }

        return -1;
    }
};
