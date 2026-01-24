class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

       if (nums.size() < 1) {
          return 0;
       } 

        int resultPointer = 1;
        int traversePointer = 1;

        int currentNum = nums[0];

        while (traversePointer < nums.size() && resultPointer < nums.size()) {
            if (nums[traversePointer] != currentNum) {
                nums[resultPointer] = nums[traversePointer];
                currentNum = nums[traversePointer];
                resultPointer++;
                traversePointer++;
            } else {
                traversePointer++;
            }
        }

        return resultPointer;
    }
};
