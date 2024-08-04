class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return 0;
        }

        if (nums.size() == 2) {
            if (nums[0] == 1 && nums[1] == 0 || (nums[0] == 0 && nums[1] == 1)) {
                return 2;
            }

            return 0;
        }

        int sum = 0;
        int edgeCase = 0;
        unordered_map<int,pair<int,int>> sumMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                sum--;
            } else {
                sum++;
            }

            if (sum == 0) {
                edgeCase = i + 1;
            }

            if (sumMap.find(sum) != sumMap.end()) {
                sumMap[sum] = {sumMap[sum].first, i};
            } else {
                sumMap.insert({sum, {i, -1}});
            }
        }

        int maxSum = edgeCase;
        for (auto sums : sumMap) {
            int left = sums.second.first;
            int right = sums.second.second;
            int size = (right - left);
            maxSum = std::max(maxSum, size);
        }

        return maxSum;
    }
};
