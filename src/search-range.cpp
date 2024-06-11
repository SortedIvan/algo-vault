class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = searchLeft(0, nums.size() - 1, nums, target);
        int right = searchRight(0, nums.size() - 1, nums, target);

        return vector<int>{left, right};
    }

    int searchLeft(int left, int right, vector<int>& nums, int target)
    {
        int mid = (left + right) / 2;

        if (left > right)
        {
            return -1;
        }

        if (nums[mid] == target)
        {
            if (mid == 0)
            {
                return 0;
            }
            
            if (nums[mid - 1] == target)
            {
                // still have to search left
                return searchLeft(0, mid - 1, nums, target);
            }
            
            return mid;
        }  

        if (nums[mid] > target)
        {
            return searchLeft(left, mid - 1, nums, target);
        } 

        return searchLeft(mid + 1, right, nums, target);
    }

    int searchRight(int left, int right, vector<int>& nums, int target)
    {
        int mid = (left + right) / 2;

        if (left > right)
        {
            return -1;
        }

        if (nums[mid] == target)
        {
            if (mid == nums.size() - 1)
            {
                return nums.size() - 1;
            }

            if (nums[mid + 1] == target)
            {
                // still have to search right
                return searchRight(mid + 1, nums.size() - 1, nums, target);
            }
            
            return mid;
        }  

        if (nums[mid] > target)
        {
            return searchRight(left, mid - 1, nums, target);
        } 

        return searchRight(mid + 1, right, nums, target);
    }
};
