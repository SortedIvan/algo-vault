class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pointer = 0;
        int curr = 0;
        int max = 0;

        while (pointer < nums.size())
        {
            if (nums[pointer] == 0)
            {
                if (curr > max)
                {
                    max = curr;
                }
                curr = 0;
            }
            else
            {
                curr++;

                if (curr > max)
                {
                    max = curr;
                }
            }

            pointer++;
        }

        return max;
    }
};
