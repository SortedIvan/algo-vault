class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }
        
        if (timeSeries.size() == 1) {
            return duration;
        }
        
        vector<int> gaps;
        int timePoisoned = 0;

        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            gaps.push_back(timeSeries[i + 1] - timeSeries[i]);
        }

        for (int i = 0; i < gaps.size(); ++i) {
            if (gaps[i] <= duration) {
                timePoisoned += gaps[i];
            }
            else {
                timePoisoned += duration;
            }
        }

        return timePoisoned + duration;
    }
};
