enum Direction {
    LEFT,
    RIGHT
};

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if (words.empty()) {
            return 0;
        }

        if (words[startIndex] == target) {
            return 0;
        }

        int startToEndMovesToTarget = getMovesToTarget(RIGHT, target, words, startIndex);
        int endToStartMovesToTarget = getMovesToTarget(LEFT, target, words, startIndex);

        if (startToEndMovesToTarget == -1 && endToStartMovesToTarget == -1) {
            return -1;
        }

        return std::min(startToEndMovesToTarget, endToStartMovesToTarget);
    }

    int getMovesToTarget(Direction dir, string target, vector<string>& words, int startIndex) {
        int currIndex = startIndex;
        int movesTraversed = 0;
        int movesLeft = words.size();

        while (movesLeft > 0) {
            if (movesTraversed == words.size()) {
                // we've looped over the entire array and didn't find anything
                return -1;
            }

            if (words[currIndex] == target) {
                return movesTraversed;
            }
            
            movesTraversed++;
            movesLeft--;
            
            if (dir == RIGHT) {
                currIndex++;
                if (currIndex == words.size()) {
                    currIndex = 0;
                }
            }
            else {
                if (currIndex == 0) {
                    currIndex = words.size() - 1;
                } else {
                    currIndex--;
                }
            }
        }

        return -1;
    }
};
