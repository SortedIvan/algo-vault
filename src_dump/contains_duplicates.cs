public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        Dictionary<int, int> duplicates = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) {
            if (duplicates.ContainsKey(nums[i])) {
                return true;
            }
            else {
                duplicates.Add(nums[i], 1);
            }
        }
        return false;
    }
}
