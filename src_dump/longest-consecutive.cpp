#include <map>
#include <utility> 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return 1;
        }

        std::map<int, int> numsMap;

        for (int i = 0; i < nums.size(); i++) {
            if (numsMap.find(nums[i]) != numsMap.end()) {
                numsMap[nums[i]] = numsMap[nums[i]] + 1;
            }
            else {
                numsMap.insert({nums[i], 1});
            }
        }

        std::vector<int> elementsPairs;
        for (auto element : numsMap) {

            if (element.second == 0) {
                continue;
            }
            elementsPairs.push_back(element.first);
        }

        int currentLongest = 1;
        int longest = 1;
        int previousElement = elementsPairs[0];

        for (int i = 1; i < elementsPairs.size(); i++) {
            if (previousElement + 1 == elementsPairs[i]) {
                currentLongest++;

                if (currentLongest > longest) {
                    longest = currentLongest;
                }
            }
            else {
                currentLongest = 1;
            }

            previousElement = elementsPairs[i];
        }


        return longest;

    }
};
