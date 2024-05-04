/*
  Sliding window approach
  Can never have more than k zeros in the window
*/

class Solution 
{
    public:
        int longestOnes(vector<int>& nums, int k) 
        {  
            int leftPointer = 0;
            int rightPointer = 0;
            int curr = 0;
            int max = 0;
            int zerosInWindow = 0;    


            while (rightPointer < nums.size())
            {
                if (nums[rightPointer] == 0)
                {
                    if (zerosInWindow == k)
                    {
                        if (nums[leftPointer] == 0)
                        {
                            leftPointer++;
                            rightPointer++;
                        }
                        else
                        {
                            leftPointer++;
                            curr--;
                        }
                    }
                    else
                    {
                        curr++;
                        zerosInWindow++;

                        if (curr > max)
                        {
                            max = curr;
                        }

                        rightPointer++;
                    }
                }
                else
                {
                    curr++;

                    rightPointer++;

                    if (curr > max)
                    {
                        max = curr;
                    }
                }
            }

            return max;
        }
};
