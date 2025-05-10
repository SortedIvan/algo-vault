class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;

        if (nums.empty()) {
            return ranges;
        }

        if (nums.size() == 1) {
            ranges.push_back(std::to_string(nums[0]));
            return ranges;
        }

        pair<int,int> currentRange = {nums[0], nums[0]};

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] + 1 == nums[i + 1]) {
                currentRange.second = nums[i+1];
            }
            else {
                ranges.push_back(convertRangePair(currentRange));
                currentRange = {nums[i + 1], nums[i + 1]};
            }
        }

        ranges.push_back(convertRangePair(currentRange));
        return ranges;
    }

    string convertRangePair(const pair<int,int> rangePair) {
        if (rangePair.first == rangePair.second) {
            return std::to_string(rangePair.first);
        }

        return std::to_string(rangePair.first) + "->" + std::to_string(rangePair.second);
    }
};
