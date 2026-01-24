class Solution {
public:
    static bool freqComparator(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;  // Ascending order by frequency
        }
        return a.first > b.first;  // Descending order by value
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> frequencyMap;
        vector<pair<int,int>> sorted;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            frequencyMap[nums[i]]++;
        }

        for (auto pair : frequencyMap) {
            sorted.push_back({pair.first, pair.second});
        }

        std::sort(sorted.begin(), sorted.end(), freqComparator);

        for (int i = 0; i < sorted.size(); i++) {
            for (int k = 0; k < sorted[i].second; k++) {
                result.push_back(sorted[i].first);
            }
        }

        return result;
    }
};
