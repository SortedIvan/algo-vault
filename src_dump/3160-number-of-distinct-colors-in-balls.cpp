class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> currentBallColors;
        vector<int> result;
        unordered_map<int, int> colorOccuranceCounter;
        
        for (int i = 0; i < currentBallColors.size(); ++i) {
            currentBallColors[i] = 0;
        }

        for (vector<int>& query : queries) {
            int ballIndex = query[0];
            int color = query[1];

            // if the ball is uncolored
            if (currentBallColors.find(ballIndex) == currentBallColors.end()) {
                colorOccuranceCounter[color]++;
                currentBallColors[ballIndex] = color;
                result.push_back(colorOccuranceCounter.size());
            }
            else if (currentBallColors[ballIndex] == color) {
                // if we are trying to paint the ball with the same color
                result.push_back(colorOccuranceCounter.size());
            }
            else {
                colorOccuranceCounter[currentBallColors[ballIndex]]--;
                if (colorOccuranceCounter[currentBallColors[ballIndex]] == 0) {
                    colorOccuranceCounter.erase(currentBallColors[ballIndex]);
                }

                // then, add the new color
                colorOccuranceCounter[color]++;
                currentBallColors[ballIndex] = color;
                result.push_back(colorOccuranceCounter.size());
            }
        }

        return result;
    }
};
