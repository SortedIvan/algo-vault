class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxBalancedSubarraySize = 0;

        for (int i = 0; i < nums.size(); ++i) {
            std::pair<int,int> evenOddBalancedCount = {0,0};
            std::unordered_set<int> subarrayElementsSet;

            for (int k = i; k < nums.size(); ++k) {
                // a subarray here is from i to k
                if (subarrayElementsSet.find(nums[k]) == subarrayElementsSet.end()) {
                    incrementCountObject(nums[k], evenOddBalancedCount);
                }

                if (evenOddBalancedCount.first == evenOddBalancedCount.second) {
                    maxBalancedSubarraySize = std::max(
                        maxBalancedSubarraySize,
                        (k - i) + 1
                    );
                }

                subarrayElementsSet.insert(nums[k]);
            }
        }

        return maxBalancedSubarraySize;
    } 

    void incrementCountObject(const int element, std::pair<int,int>& evenOddBalancedCount) {
        if (element % 2 == 0) {
            evenOddBalancedCount = {evenOddBalancedCount.first + 1, evenOddBalancedCount.second};
        }
        else {
            evenOddBalancedCount = {evenOddBalancedCount.first, evenOddBalancedCount.second + 1};
        }
    }
};
