class Solution {
public:
    void sortColors(vector<int>& nums) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;
        int lastOccuredSymbolIndex = -1;

        if (nums.size() == 1) 
        {
            return;
        }

        // sort 2's
        while (leftPointer < rightPointer)
        {
            if (nums[rightPointer] < 2 && nums[leftPointer] == 2)
            {
                int temp = nums[rightPointer];
                nums[rightPointer] = 2;
                nums[leftPointer] = temp;

                leftPointer++;
                rightPointer--;
                continue; 
            }

            if (nums[leftPointer] == 2 && nums[rightPointer] == 2)
            {
                rightPointer--;
                continue;
            }

            if (nums[leftPointer] < 2 && nums[rightPointer] < 2)
            {
                leftPointer++;
                continue;
            }

            if (nums[leftPointer] < 2 && nums[rightPointer] == 2)
            {
                rightPointer--;
                continue;
            }

            break;
        }

        leftPointer = 0;

        std::cout << rightPointer << std::endl;

        while (nums[rightPointer] == 2) {
            rightPointer--;
            
            if (rightPointer < leftPointer) {
                break;
            }
        }

        while (leftPointer < rightPointer)
        {
            
            if (nums[leftPointer] == 1 && nums[rightPointer] == 0)
            {
                int temp = nums[rightPointer];
                nums[rightPointer] = 1;
                nums[leftPointer] = temp;

                leftPointer++;
                rightPointer--;
                continue; 
            }
            
            if (nums[rightPointer] == 0 && nums[leftPointer] == 1)
            {
                int temp = nums[rightPointer];
                nums[rightPointer] = 1;
                nums[leftPointer] = temp;

                leftPointer++;
                rightPointer--;
                continue; 
            }

            if (nums[leftPointer] == 1 && nums[rightPointer] == 1)
            {
                rightPointer--;
                continue;
            }

     
            if (nums[leftPointer] ==0 && nums[rightPointer] == 0)
            {
                leftPointer++;

                continue;
            }

            if (nums[leftPointer] == 0 && nums[rightPointer] == 1)
            {
                rightPointer--;
                continue;
            }
            break;
        }
    }
};
