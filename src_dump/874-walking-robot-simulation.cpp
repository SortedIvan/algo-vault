class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int currDirection = 0;
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        set<pair<int,int>> obstacleMap;
        pair<int,int> currPosition = {0,0};
        pair<int,int> furthestPoint = {0,0};
        int commandPointer = 0;

        for (const auto& obstacle : obstacles) {
            obstacleMap.insert({obstacle[0], obstacle[1]});
        }
        
        while (commandPointer < commands.size()) {
            int command = commands[commandPointer];
            commandPointer++;

            if (command == -1 || command == -2) {
                bool left = command == -1 ? false : true; 
                switchDirection(left, directions, currDirection);
            }
            else {
                while (command > 0) {
                    command--;
                    pair<int,int> newPosition = currPosition;
                    newPosition.first += directions[currDirection].first;
                    newPosition.second += directions[currDirection].second;
                    
                    if (!obstacles.empty() && obstacleMap.find(newPosition) != obstacleMap.end()) {
                        break;
                    }

                    currPosition = newPosition;

                    if (checkIfPointIsFurther(furthestPoint, currPosition)) {
                        furthestPoint = currPosition;
                    }
                }
            }
        }

        return furthestPoint.first * furthestPoint.first + furthestPoint.second * furthestPoint.second;
    }

    bool checkIfPointIsFurther(pair<int,int>& currentFurthest, pair<int,int>& newCandidate) {
        int currDistance = currentFurthest.first * currentFurthest.first + currentFurthest.second * currentFurthest.second;
        int newDistance = newCandidate.first * newCandidate.first + newCandidate.second * newCandidate.second;

        if (currDistance < newDistance) {
            return true;
        }

        return false;
    }

    void switchDirection(bool left, vector<pair<int,int>>& directions, int& currDirection) {
        if (left) {
            if (currDirection == 0) {
                currDirection = directions.size() - 1;
            }
            else {
                currDirection--;
            }
        }
        else {
            if (currDirection == directions.size() - 1) {
                currDirection = 0;
            }
            else {
                currDirection++;
            }
        }
    }
};
