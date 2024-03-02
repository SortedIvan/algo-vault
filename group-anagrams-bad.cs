public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        List<IList<string>> result = new List<IList<string>>();
        Dictionary<string, List<string>> allStrs = new Dictionary<string, List<string>>();

        for (int i = 0; i < strs.Length; i++) {
            string sorted = new string(MergeSort(strs[i].ToCharArray()));

            if (allStrs.ContainsKey(sorted)) {
                allStrs[sorted].Add(strs[i]);
            }
            else {
                List<string> newList = new List<string>();
                newList.Add(strs[i]);
                allStrs.Add(sorted, newList);
            }
        }

        foreach(var item in allStrs) {
            result.Add(item.Value);
        }
 

        return result;
    }

    public char[] MergeSort(char[] input) {

        if (input.Length == 0) {
            return input;
        }

        if (input.Length == 1) {
            return input;
        }

        int mid = input.Length / 2;
        int leftSize = mid;
        int rightSize = input.Length - mid;

        char[] leftArray = new char[leftSize];
        char[] rightArray = new char[rightSize];

        for (int i = 0; i < leftSize; i++) {
            leftArray[i] = input[i];
        }

        for (int i = 0; i < rightSize; i++) {
            rightArray[i] = input[mid + i];
        }

        leftArray = MergeSort(leftArray);
        rightArray = MergeSort(rightArray);

        return Merge(leftArray, rightArray);
    }

    public char[] Merge(char[] left, char[] right) {
        int leftPointer = 0;
        int rightPointer = 0;
        int resultPointer = 0;
        char[] result = new char[left.Length + right.Length];

        while (leftPointer < left.Length && rightPointer < right.Length) {
            if (left[leftPointer] < right[rightPointer]) {
                result[resultPointer] = left[leftPointer];
                resultPointer++;
                leftPointer++;
            }
            else {
                result[resultPointer] = right[rightPointer];
                resultPointer++;
                rightPointer++;
            }
        }

        // push any remaining chars left

        while (leftPointer < left.Length) {
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
