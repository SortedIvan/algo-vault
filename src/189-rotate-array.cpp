class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotations = k;

        if (k > nums.size())
        {
            rotations = k % nums.size();
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }

        left = 0;
        right = rotations - 1;

        while (left < right) 
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }

        left = rotations;
        right = nums.size() - 1;

        while (left < right) 
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }

    }
};
