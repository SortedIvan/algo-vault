class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> intCount;
        int biggestLuckyInt = -1;

        for (int i = 0; i < arr.size(); ++i) {
            intCount[arr[i]]++;
        }

        for (auto pair : intCount) {
            if (pair.first == pair.second) {
                biggestLuckyInt = std::max(pair.first, biggestLuckyInt);
            }
        }

        return biggestLuckyInt;
    }
};
