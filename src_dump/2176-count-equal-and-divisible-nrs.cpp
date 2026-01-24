class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> equalNumberIndices;
        int result = 0;

        std::cout << 5 % 2 << std::endl;

        for (int i = 0; i < nums.size(); ++i) {
            equalNumberIndices[nums[i]].push_back(i);
        }

        for (const auto pair : equalNumberIndices) {
            if (pair.second.size() == 1) {
                continue;
            }

            for (int i = 0; i < pair.second.size(); ++i) {
                int firstNum = pair.second[i];
                for (int z = i + 1; z < pair.second.size(); ++z) {
                    if ((firstNum * pair.second[z]) % k == 0) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};
