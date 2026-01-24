class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> numMap;

        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            if (numMap.find(nums[i]) != numMap.end())
            {
                numMap[nums[i]] += 1;
            }
            else
            {
                numMap.insert({nums[i], 1});
            }
        }
        
        bool leftOver = true;

        while (leftOver)
        {
            leftOver = false;
            vector<int> row;

            for (auto i = numMap.begin(); i != numMap.end(); ++i) 
            {
                if (i->second == 0)
                {
                    continue;
                }

                row.push_back(i->first);
                i->second--;

                if (i->second != 0)
                {
                    leftOver = true;
                }
            }

            result.push_back(row);
        }

        return result;
    }
};
