class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int counter = 1;
        std::vector<int> result;
        
        if (nums.size() == 0)
        {
            return result;
        }

        while (counter < nums.size())
        {
            for (int i = 0; i < nums[counter - 1]; i++)
            {
                result.push_back(nums[counter]);
            }

            counter += 2;
        }

        return result;
    }
};
