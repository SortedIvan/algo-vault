class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        std::vector<int> result;
        std::map<int, int> numMap;

        for (int i = 0; i < arr1.size(); ++i) {
            if (numMap.find(arr1[i]) != numMap.end()) {
                numMap[arr1[i]]++;
            } else {
                numMap.insert({arr1[i], 1});
            }
        }

        for (int i = 0; i < arr2.size(); ++i) {
            if (numMap.find(arr2[i]) != numMap.end() && numMap[arr2[i]] > 0) {

                for (int k = 0; k < numMap[arr2[i]]; k++) {
                    result.push_back(arr2[i]);
                }

                numMap[arr2[i]] = 0;
            }
        }

        for (auto num = numMap.begin(); num != numMap.end(); ++num) {
            if (num->second > 0) {
                for (int i = 0; i < num->second; i++) {
                    result.push_back(num->first);
                }
            }
        }

        return result;
    }
};
