class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        bool isSorted = false;
        int numberOfOperations = 0;

        while (!isSorted) {
            isSorted = true;

            if (nums.size() == 1) {
                break;
            }

            pair<int, int> minIndexPair = {0, 1};

            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[minIndexPair.first] + nums[minIndexPair.second] > nums[i] + nums[i + 1]) {
                    minIndexPair = {i, i + 1};
                }

                if (nums[i] > nums[i + 1]) {
                    isSorted = false;
                }
            }

            if (!isSorted) {
                int minSum = nums[minIndexPair.first] + nums[minIndexPair.second];
                nums[minIndexPair.first] = minSum;
                nums.erase(nums.begin() + minIndexPair.second);
                numberOfOperations++;
            }

        }

        return numberOfOperations;
    }
};
