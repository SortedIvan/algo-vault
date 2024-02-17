public class Solution {
    public int[] TwoSum(int[] nums, int target) {

        int[] numsSorted = MergeSort(nums); // sort the nums recursively, O(nlogn)
        int[] result = new int[2];

       int replacement = -1000000001;


        // IDEA:
        // Have two pointers, one for the beginning, one for the right
        // if leftPointer + rightPointer > target, decrease rightPointer
        // if leftPointer + rightPointer < target, increase leftPointer
        // if they cross, stop, no valid sum

        int leftPointer = 0;
        int rightPointer = numsSorted.Length - 1;

        while (leftPointer <= rightPointer) {
            if (numsSorted[leftPointer] + numsSorted[rightPointer] > target) {
                rightPointer--;
                continue;
            }

            if (numsSorted[leftPointer] + numsSorted[rightPointer] < target) {
                leftPointer++;
                continue;
            }

            if (numsSorted[leftPointer] + numsSorted[rightPointer] == target) {
                result[0] = numsSorted[leftPointer];
                result[1] = numsSorted[rightPointer];
                break;
            }
        }

        // finally, linearly traverse the original array and find the positions of the two numbers
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] == result[0]) {
                nums[i] = replacement;
                result[0] = i;
                break;
            } 
        }
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] == result[1]) {
                nums[i] = replacement;
                result[1] = i;
                break;
            } 
        }

        return result;


    }

    public static int[] MergeSort(int[] nums) {

            if (nums.Length == 1) {
                // only one element, already sorted
                return nums;
            }

            int half = nums.Length / 2;

            int[] leftHalf = new int[half];
            int[] rightHalf = new int[nums.Length - half];

            for (int i = 0; i < leftHalf.Length; i++){
                leftHalf[i] = nums[i];
            }

            for (int i = 0; i < rightHalf.Length; i++) {
                rightHalf[i] = nums[i + half];
            }

            leftHalf = MergeSort(leftHalf);
            rightHalf = MergeSort(rightHalf);

            return Merge(leftHalf, rightHalf);
    }

	public static int[] Merge(int[] leftHalf, int[] rightHalf) {

		// merge the split & sort at the same time
		// since arrays can be different sizes, we create a pointer for each
		// furthermore, we define an array which will hold the result of the merge
		int[] result = new int[leftHalf.Length + rightHalf.Length];
		int resultPointer = 0;
		int leftPointer = 0;
		int rightPointer = 0;

		while (leftPointer < leftHalf.Length && rightPointer < rightHalf.Length) {
			if (leftHalf[leftPointer] < rightHalf[rightPointer]) {
				// element from the right is bigger
				// slot the left element and continue scanning with the right
				result[resultPointer] = leftHalf[leftPointer];
				leftPointer++;
				resultPointer++;
			}
			else {
				result[resultPointer] = rightHalf[rightPointer];
				resultPointer++;
				rightPointer++;
			}

		}

		// Copy over any remaining elements
		while (leftPointer < leftHalf.Length){
			result[resultPointer] = leftHalf[leftPointer];
			leftPointer++;
			resultPointer++;
		}

		while (rightPointer < rightHalf.Length){
			result[resultPointer] = rightHalf[rightPointer];
			rightPointer++;
			resultPointer++;
		}

		return result;

	}


}
