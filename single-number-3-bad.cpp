class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> numMap;

        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {   
            if (numMap.find(nums[i]) != numMap.end())
            {
                numMap[nums[i]]++;
            }
            else
            {
                numMap.insert({nums[i], 1});
            }
        }

        for (auto i = numMap.begin(); i != numMap.end(); ++i)
        {
            if (i->second == 1)
            {  
                result.push_back(i->first);
            }
        }

        return result;
    }
};
