public class Solution {
    public int MaxFrequencyElements(int[] nums) {
        Dictionary<int, int> frequencies = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) {
            if (!frequencies.ContainsKey(nums[i])) {
                frequencies.Add(nums[i], 1);
                continue;
            }

            frequencies[nums[i]] = frequencies[nums[i]] + 1;   
        }

        int biggest = 0;
        int biggestNr = 0;
        int totalFrequency = 0;
        foreach (var item in frequencies) {
            if (item.Value > biggest) {
                biggest = item.Value;
                biggestNr = item.Key;
            }
        }

        foreach (var item in frequencies) {
            if (item.Value == biggest) {
                totalFrequency += item.Value;
            }   
        }

        return totalFrequency;
    }
}
