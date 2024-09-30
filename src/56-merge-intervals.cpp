class Solution {
private: 
    static bool customSortComparator(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return a[0] < b[0];
        }

        if (a[0] == b[0]) {
            return a[1] < b[1];
        }

        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // first, sort the intervals
        // second, merge using two pointers & create new arrays for each new merge
        // return result
        std::sort(intervals.begin(), intervals.end(), customSortComparator);
        
        int pointer = 0;
        while (pointer < intervals.size() - 1) {
            vector<int> intervalA = intervals[pointer];
            vector<int> intervalB = intervals[pointer + 1];

            if (intervalA[1] >= intervalB[0]) {
                int intervalStart = std::min(intervalA[0], intervalB[0]);
                int intervalEnd = std::max(intervalB[1], intervalA[1]);
                intervals[pointer] = vector<int> {intervalStart, intervalEnd};
                intervals.erase(intervals.begin() + pointer + 1);
                continue;
            }

            pointer++;
        }

        return intervals;
    }
};
