public class Solution {
    public int MaxArea(int[] height) {
        
        if (height.Length == 0 || height.Length == 1) {
            return 0;
        }

        int leftPointer = 0;
        int rightPointer = height.Length - 1;
        int maxWater = 0;

        while (leftPointer < rightPointer) {
            if (height[leftPointer] < height[rightPointer]) {
                int heightOffset = height[rightPointer] - height[leftPointer];
                int actualHeight = height[rightPointer] - heightOffset;
                int currentWater = (rightPointer - leftPointer) * actualHeight;

                if (currentWater > maxWater) {
                    maxWater = currentWater;
                }
                
                leftPointer++;
            }
            else {
                int heightOffset = height[leftPointer] - height[rightPointer];
                int actualHeight = height[leftPointer] - heightOffset;
                int currentWater = (rightPointer - leftPointer) * actualHeight;

                if (currentWater > maxWater) {
                    maxWater = currentWater;
                }

                rightPointer--;
                
            }
        }

        return maxWater;

    }
}
