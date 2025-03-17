class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if (nums.size() % 2 != 0) {
            return false;
        }

        unordered_map<int, int> numCounter;

        for (int i = 0; i < nums.size(); ++i) {
            numCounter[nums[i]]++;
        }

        for (auto& pair : numCounter) {
            if (pair.second % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};
