using System;
					
public class Program
{
	public static void Main()
	{

		int[] inputArray = new int[] { 4, 3, 12, 1, 5, 5, 3, 9 };
		int max = FindMax(inputArray);
		int[] countArray = FillCountArray(inputArray, inputArray[max]+1);
		
		int[] sorted = CountSort(inputArray, countArray, inputArray.Length);
		
		for (int i = 0; i < sorted.Length; i++){
			Console.WriteLine(sorted[i]);	
		}
		
	}
	
	public static int FindMax(int[] inputArray){
		//1) Find the max element from the input
		
		if (inputArray.Length == 0) {
			return 0;
		}
		
		int max = 0; 
		for (int i = 0; i < inputArray.Length; i++){
			if (inputArray[max] < inputArray[i]) {
				max = i;
			}
		}
		
		return max;
	}
	
	public static int CountOccuranceOfElement(int element, int[] arr){
		int count = 0;
		
		for (int i = 0; i < arr.Length; i++){
			if (arr[i] == element){
				count++;
			}
		}
		
		return count;
	}
		
	public static int[] FillCountArray(int[] arr, int size) {
		int[] temp = new int[size];
		for (int i = 0; i < arr.Length; i++){
			int count = CountOccuranceOfElement(arr[i], arr);
			temp[arr[i]] = count;
		}
		
		// Take the prefix
		for (int i = 1; i < size; i++){
			temp[i] = temp[i] + temp[i-1];
		}
		
		return temp;
	}
	
	public static int[] CountSort(int[] input, int[] count, int size){
		int[] sorted = new int[size];
		for (int i = size; i >= 0; i--){
			sorted[count[input[i]]-1] = input[i];
		}
		
		return sorted;
	
	}
	
}
