class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        vector<bool> occuranceMap;

        for (int i = 0; i < nums.size(); ++i) {
            occuranceMap.push_back(false);
        }

        for (int i = 0; i < nums.size(); ++i) {
            occuranceMap[nums[i] - 1] = true;
        }

        for (int i = 0; i < occuranceMap.size(); ++i) {
            if (!occuranceMap[i]) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};
