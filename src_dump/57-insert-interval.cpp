class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int pointer = 0;

        vector<vector<int>> result;


        while (pointer < intervals.size() && intervals[pointer][1] < newInterval[0]) {
            result.push_back(intervals[pointer]);
            pointer++;
        }

        while (pointer < intervals.size() && intervals[pointer][0] <= newInterval[1]) { 
            newInterval = {std::min(intervals[pointer][0], newInterval[0]),
                           std::max(intervals[pointer][1], newInterval[1])};
            pointer++;
        }

        result.push_back(newInterval);

        while (pointer < intervals.size()) {
            result.push_back(intervals[pointer]);
            pointer++;
        }

        return result;
    }
};
