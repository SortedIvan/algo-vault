class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indexMap;
        for (int i = 0; i < nums.size(); ++i) {
            indexMap[nums[i]].push_back(i);
        }

        for (const auto& pair : indexMap) {
            
            if (pair.second.size() < 2) {
                continue;
            }
            
            for (int i = 0; i < pair.second.size() - 1; ++i) {
                if (pair.second[i + 1] - pair.second[i] <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};
