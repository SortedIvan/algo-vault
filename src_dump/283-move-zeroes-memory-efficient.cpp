class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int resultPointer = nums.size() - 1;
        bool finished = false;

        while (!finished && resultPointer > 0) {
            finished = true;

            for (int i = 0; i < resultPointer + 1; ++i) {
                if (nums[i] == 0) {
                    finished = false;
                    moveZeroToBack(nums, i, resultPointer + 1);
                    resultPointer--;
                }
            }
        }
    }

    void moveZeroToBack(vector<int>& nums,int start, int end) {
        for (int i = start; i < end - 1; ++i) {
            std::swap(nums[i], nums[i+1]);
        } 
    }
};
