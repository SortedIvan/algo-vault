public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {

        Dictionary<int, int> numsDict = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) {
            if (numsDict.ContainsKey(nums[i])) {
                numsDict[nums[i]] = numsDict[nums[i]] + 1; 
            }
            else {
                numsDict.Add(nums[i], 1);
            }
        }

        Tuple<int, int>[] result = new Tuple<int, int>[numsDict.Count];
        int pointer = 0;
        foreach (var v in numsDict) {
            result[pointer] = Tuple.Create(v.Key, v.Value);
            pointer++;
        }

        result = MergeSort(result);

        int[] output = new int[k];
        pointer = 0;

        for (int i = result.Length - k; i < result.Length; i++) {
            output[pointer] = result[i].Item1;
            pointer++;
        }

        return output;
    }

    public Tuple<int,int>[] MergeSort(Tuple<int,int>[] input) {

        if (input.Length == 1) {
            return input;
        }

        int mid = input.Length / 2;
        
        Tuple<int, int>[] left = new Tuple<int, int>[mid];
        Tuple<int, int>[] right = new Tuple<int, int>[input.Length - mid];

        for (int i = 0; i < left.Length; i++) {
            left[i] = Tuple.Create(input[i].Item1, input[i].Item2);
        }

        for (int i = 0; i < right.Length; i++) {
            right[i] = input[mid+i];
        }

        left = MergeSort(left);
        right = MergeSort(right);


        return Merge(left, right);
    } 

    public Tuple<int, int>[] Merge(Tuple<int, int>[] left, Tuple<int, int>[] right) {

        int leftPointer = 0;
        int rightPointer = 0;
        int resultPointer = 0;
        Tuple<int, int>[] result = new Tuple<int, int>[left.Length + right.Length];

        while (leftPointer < left.Length && rightPointer < right.Length) {
            if (left[leftPointer].Item2 < right[rightPointer].Item2) {
                result[resultPointer] = left[leftPointer];
                resultPointer++;
                leftPointer++;
            }
            else {
                result[resultPointer] = right[rightPointer];
                rightPointer++;
                resultPointer++;
            }
        }

        while(leftPointer < left.Length) {
            result[resultPointer] = left[leftPointer];
            resultPointer++;
            leftPointer++;
        }

        while (rightPointer < right.Length) {
            result[resultPointer] = right[rightPointer];
            resultPointer++;
            rightPointer++;
        }

        return result;
    }

}
