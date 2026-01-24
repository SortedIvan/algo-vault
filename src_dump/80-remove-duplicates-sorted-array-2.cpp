class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }   

        if (nums.size() == 1) {
            return 1;
        }

        int traversePointer = 1;
        int resultPointer = 1;
        int currentNum = nums[0];
        int currentNumCount = 1;

        while (traversePointer < nums.size() && resultPointer < nums.size()) {
            if (currentNum == nums[traversePointer] && currentNumCount < 2) {
                currentNumCount++; 
                nums[resultPointer] = nums[traversePointer];
                traversePointer++;
                resultPointer++;
            } else if (currentNum == nums[traversePointer] && currentNumCount == 2) {
                traversePointer++;
            } else if (currentNum != nums[traversePointer]) {
                nums[resultPointer] = nums[traversePointer];
                currentNumCount = 1;
                currentNum = nums[traversePointer];
                traversePointer++;
                resultPointer++;
            }
        }

        return resultPointer;
    }
};
