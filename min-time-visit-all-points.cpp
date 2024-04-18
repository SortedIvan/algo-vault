class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int totalDistance = 0;

        for (int i = 0; i < points.size() - 1; i++)
        {
            
            if (abs(points[i+1][1] - points[i][1]) > abs(points[i+1][0] - points[i][0]))
            {
                int distanceY = points[i+1][1] - points[i][1];
                totalDistance += std::abs(distanceY);
            }
            else 
            {
                int distanceX = points[i+1][0] - points[i][0];
                totalDistance += std::abs(distanceX);
            }

        }

        return totalDistance;

    }
};
