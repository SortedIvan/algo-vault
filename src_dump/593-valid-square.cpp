class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        bool allDistancesEqual = checkIfAllPointsHaveEqualDistance(p1, p2, p3, p4);
        bool allPointsUnique = checkAllPointsUnique(p1,p2,p3,p4);

        return allDistancesEqual && allPointsUnique;
    }

    bool checkAllPointsUnique(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return checkTwoPointsUnique(p1, p2) 
            && checkTwoPointsUnique(p1, p3)
            && checkTwoPointsUnique(p1, p4) 
            && checkTwoPointsUnique(p2, p3)
            && checkTwoPointsUnique(p3, p4)
            && checkTwoPointsUnique(p2, p4);
    }

    bool checkTwoPointsUnique(vector<int>& p1, vector<int>& p2) {
        return (p1[0] != p2[0]) || (p1[1] != p2[1]);
    }

    bool checkIfAllPointsHaveEqualDistance(vector<int>& p1, 
        vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> distances;

        distances[dist(p1, p2)]++;
        distances[dist(p1, p3)]++;
        distances[dist(p1, p4)]++;
        distances[dist(p2, p3)]++;
        distances[dist(p2, p4)]++;
        distances[dist(p3, p4)]++;

        if (distances.size() != 2) {
            return false;
        }

        vector<int> times;

        for (auto pair : distances) {
            times.push_back(pair.second);
        }

        if ((times[0] == 4 && times[1] == 2)
        || (times[0] == 2 && times[1] == 4)) {
            return true;
        } 

        return false;
    }

    int dist(vector<int>& p1, vector<int>& p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
};
