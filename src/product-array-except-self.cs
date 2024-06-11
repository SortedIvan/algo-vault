public class Solution {
    public int[] ProductExceptSelf(int[] nums) {    
        int[] prefix = new int[nums.Length];
        int[] suffix = new int[nums.Length];
        int[] result = new int[nums.Length];

        for (int i = 0; i < nums.Length; i++) {
            if (i == 0) {
                prefix[0] = nums[0];
                continue;
            }
            prefix[i] = nums[i] * prefix[i-1];
        }

        for (int i = nums.Length -1; i >= 0; i--) {
            if (i == nums.Length - 1) {
                suffix[i] = nums[i];
                continue;
            }
            suffix[i] = suffix[i+1] * nums[i];
        }

        for (int i = 0; i < nums.Length; i++) {
            if (i == 0) {
                result[i] = suffix[i+1];
                continue;
            }

            if (i == nums.Length - 1){
                result[i] = prefix[nums.Length - 2];
                continue;
            }

            result[i] = prefix[i-1] * suffix[i+1];
        }

        return result;

    }
}
