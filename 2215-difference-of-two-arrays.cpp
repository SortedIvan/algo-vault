class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result;
        vector<int> num1res;
        vector<int> num2res;

        map<int, int> numMap;

        for (int i = 0; i < nums1.size(); ++i) {
            if (numMap.find(nums1[i]) == numMap.end()) {
                numMap.insert({nums1[i], 1});
            }
        }

        for (int i = 0; i < nums2.size(); ++i) {
            if (numMap.find(nums2[i]) != numMap.end() && numMap[nums2[i]] != 2) {
                numMap[nums2[i]] = -1;
            } else {
                numMap.insert({nums2[i], 2});
            }
        }

        for (auto num = numMap.begin(); num != numMap.end(); ++num) {
            if (num->second == 1) {
                num1res.push_back(num->first);
            } else if (num->second == 2) {
                num2res.push_back(num->first);
            }
        }

        result.push_back(num1res);
        result.push_back(num2res);

        return result;
    }
};
