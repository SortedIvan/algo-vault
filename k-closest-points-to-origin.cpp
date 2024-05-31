class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int>, vector<pair<float,int>>, greater<pair<float,int>>> pq;

        vector<vector<int>> result;

        for (int i = 0; i < points.size(); i++)
        {
            float distance = std::sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            pq.push(std::make_pair(distance, i));
        }

        while (k > 0)
        {
            pair<float, int> heapElement = pq.top();
            pq.pop();
            result.push_back(points[heapElement.second]);

            k--;
        }

        return result;
    }
};
