public class Solution {
    public int[] SortedSquares(int[] nums) {
        
        int leftPointer = 0;
        int rightPointer = nums.Length - 1;
        int[] output = new int[nums.Length];
        int resultPointer = nums.Length - 1;

        while (leftPointer < rightPointer+1) {
            if (Math.Abs(nums[leftPointer]) < Math.Abs(nums[rightPointer])) {
                output[resultPointer] = nums[rightPointer] * nums[rightPointer];
                rightPointer--;
            }
            else {
                output[resultPointer] = nums[leftPointer] * nums[leftPointer];
                leftPointer++;
            }

            resultPointer--;
        }

        return output;
    }
}
