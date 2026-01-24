class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        
        for (int i = 0; i < timePoints.size(); ++i) {

            std::string hours = timePoints[i].substr(0, 2);  
            std::string minutes = timePoints[i].substr(3, 2);  

            time.push_back(
                60 * std::stoi(hours) + std::stoi(minutes)
            );
        }

        int smallestDifference = std::numeric_limits<int>::max();

        for (int i = 0; i < time.size(); ++i) {
            int num1 = time[i];
            for (int k = 0; k < time.size(); ++k) {

                if (i == k) {
                    continue;
                }

                int num2 = time[k];
                
                int diff1 = 0;
                int diff2 = 0;

                if (num1 > num2) {
                    diff1 = num1 - num2;
                    diff2 = (1440 - num1) + num2;
                }
                else {
                    diff1 = num2 - num1;
                    diff2 = (1440 - num2) + num1;
                }


                int realDiff = std::min(diff1, diff2);
                smallestDifference = std::min(realDiff, smallestDifference);
            }
        }

        return smallestDifference;
    }
};
