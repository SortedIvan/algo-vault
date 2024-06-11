#include <map>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, int> indexMap;
        std::vector<int> result;
        bool found = false;

        for (int i = 0; i < nums2.size(); i++) {
            indexMap.insert({nums2[i], i});
        }


        // the elements of nums1 is a subset of nums2 (nums1 contains a part of nums2)
        // nums2 contains ALL elements of nums1
        for (int i = 0; i < nums1.size(); i++) {
            int elementIndex = indexMap[nums1[i]];
            found = false;

            // try to optimize with these cases
            if (elementIndex + 1 == nums2.size()) {
                result.push_back(-1);
                continue;
            }
            if (nums2[elementIndex + 1] > nums2[elementIndex]) {
                result.push_back(nums2[elementIndex + 1]);
                continue;
            }

            for (int k = elementIndex + 1; k < nums2.size(); k++) {
                if (nums2[k] > nums2[elementIndex]) {
                    result.push_back(nums2[k]);
                    found = true;
                    break;
                }
            }

            if (!found) {
                result.push_back(-1);
            }
            
        }

        return result;

    }
};
