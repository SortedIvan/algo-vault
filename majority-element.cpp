class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int counter = 0;
        int currentMajorElement = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == currentMajorElement)
            {
                counter++;
            }
            else
            {
                if (counter == 0)
                {
                    currentMajorElement = nums[i];
                    counter = 1;
                }
                else
                {
                    counter--;
                }
            }
        }

        return currentMajorElement;
    }
};
