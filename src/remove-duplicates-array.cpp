class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int resultPointer = 0;
        int traversePointer = 1;
        int currentNumber = nums[0];

        if (nums.size() == 1) {
            return 1;
        }


        while (traversePointer < nums.size()) {
            if (currentNumber != nums[traversePointer]) {
                nums[resultPointer] = currentNumber;
                currentNumber = nums[traversePointer];
                resultPointer++;
                traversePointer++;
            }
            else {
                traversePointer++;
            }
        }

        if (currentNumber != nums[resultPointer]) {
            nums[resultPointer] = currentNumber;
        }

        return resultPointer + 1;
    }
};
