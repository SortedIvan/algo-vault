class Solution {
private:
    static bool customSortOnValue(const pair<int,int>& a, const pair<int,int>& b) {
        return a.first < b.first;
    }

    static bool customSortOnIndex(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        /*
            Idea: 
            1. re-create array with pairs (element, index in original)
            2. Sort on element
            3. Get the last k elements
            4. Sort new array on indices
            5. Return new array with elements in that order
        */

        vector<int> result;
        vector<pair<int,int>> elementIndexArray;
        vector<pair<int,int>> elementIndexArrayResult;
        
        for (int i = 0; i < nums.size(); ++i) {
            elementIndexArray.push_back({nums[i], i});
        } 

        std::sort(elementIndexArray.begin(), elementIndexArray.end(), customSortOnValue); 

        int iterator = elementIndexArray.size() - 1;

        while (k > 0) {
            elementIndexArrayResult.push_back(elementIndexArray[iterator]);
            iterator--;
            k--;
        }

        std::sort(elementIndexArrayResult.begin(), elementIndexArrayResult.end(), customSortOnIndex); 

        for (int i = 0; i < elementIndexArrayResult.size(); ++i) {
            result.push_back(elementIndexArrayResult[i].first);
        }

        return result;
    }
};
