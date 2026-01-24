class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if (!nums.size())
        {
            return 0;
        }

        if (nums.size() == 1)
        {

            if (nums[0] == val)
            {
                return 0;
            }

            return 1;
        }

        int left = 0;

        while (left < nums.size())
        {
            if (nums[left] == val)
            {
                int right = left + 1;
                bool found = false;
                
                while (right < nums.size())
                {
                    if (nums[right] != val)
                    {
                        nums[left] = nums[right];
                        nums[right] = val;
                        found = true;
                        break;
                    }
                    else
                    {
                        right++;
                    }
                }

                if (!found)
                {
                    return left;
                }
                
                left++;
            }
            else
            {
                left++;
            }
        }

        return left;
    }
};
