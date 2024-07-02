class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> numbers;

        for (int i = 0; i < nums1.size(); i++) {
            if (numbers.find(nums1[i]) != numbers.end()) {
                numbers[nums1[i]].first++;
            } else {
                numbers.insert({nums1[i], {1, 0}});
            }
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (numbers.find(nums2[i]) != numbers.end()) {
                numbers[nums2[i]].second++;
            }
        }

        vector<int> result;

        for (auto element : numbers) {
            if (element.second.first != 0 && element.second.first != 0) {
                int amount = std::min(element.second.first, element.second.second);

                for (int k = 0; k < amount; ++k) {
                    result.push_back(element.first);
                }
            }
        }

        return result;
    } 
};
