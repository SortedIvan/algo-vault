enum Operation {
    Bigger,
    Equal,
    Less
};

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        collectNums(result, nums, Less, pivot);
        collectNums(result, nums, Equal, pivot);
        collectNums(result, nums, Bigger, pivot);
        return result;
    }
    
    void collectNums(vector<int>& result,vector<int>& nums, Operation operation, int pivot) {
        for (int i = 0; i < nums.size(); ++i) {
            if (operation == Bigger && nums[i] > pivot) {
                result.push_back(nums[i]);
            }
            else if (operation == Less && nums[i] < pivot) {
                result.push_back(nums[i]);
            }
            else if (operation == Equal && nums[i] == pivot) {
                result.push_back(nums[i]);
            }
        }
    }
    
};
