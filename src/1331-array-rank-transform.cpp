class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        std::sort(temp.begin(), temp.end());
        unordered_map<int, int> ranking;
        int rankCounter = 1;

        for (int i = 0; i < temp.size(); ++i) {
            if (ranking.find(temp[i]) == ranking.end()) {
                ranking[temp[i]] = rankCounter;
                rankCounter++;
            }
        }

        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = ranking[arr[i]];
        }

        return arr;
    }
};
