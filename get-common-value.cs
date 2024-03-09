public class Solution {
    public int GetCommon(int[] nums1, int[] nums2) {
        Dictionary<int,Tuple<int, int>> result = new Dictionary<int,Tuple<int, int>>();

        for (int i = 0; i < nums1.Length; i++) {
            if (!result.ContainsKey(nums1[i])) {
                result.Add(nums1[i], Tuple.Create(1, 0));
            }
            else {
                result[nums1[i]] = Tuple.Create(result[nums1[i]].Item1 + 1, 0);
            }
        }

        for (int i = 0; i < nums2.Length; i++) {
            if (!result.ContainsKey(nums2[i])) {
                result.Add(nums2[i], Tuple.Create(0, 1));
            }
            else {
                result[nums2[i]] = Tuple.Create(result[nums2[i]].Item1, result[nums2[i]].Item2 + 1);
            }
        }

        foreach (var item in result) {
            if (item.Value.Item1 > 0 && item.Value.Item2 > 0) {
                return item.Key;
            }
        }

        return -1;


    }
}
