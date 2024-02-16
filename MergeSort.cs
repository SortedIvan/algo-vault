using System;
using System.Collections;
using System.Collections.Generic;
					
public class Program
{
	public static void Main()
	{
		int[] input = new int[]{1,10,5,3,9,100,11,7,4};
		
		int[] result = MergeSort(input);
		
		for (int i = 0; i < result.Length; i++){
			Console.WriteLine(result[i]);	
		}
		
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
