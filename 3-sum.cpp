#include <map>
#include <array>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::set<vector<int>> resultSet;

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int leftPointer = i + 1;
            int rightPointer = nums.size() - 1;

            while (leftPointer < rightPointer) {
                if (nums[leftPointer] + nums[rightPointer] == target) {
                    resultSet.insert({-target , nums[leftPointer], nums[rightPointer]});
                    leftPointer++;
                    rightPointer--;
                    continue;
                }

                if (nums[leftPointer] + nums[rightPointer] < target) {
                    leftPointer++;
                    continue;
                }

                if (nums[leftPointer] + nums[rightPointer] > target) {
                    rightPointer--;
                    continue;
                }
            }
        }

        std::vector<std::vector<int>> result(resultSet.begin(), resultSet.end());
        return result;
    }

};
