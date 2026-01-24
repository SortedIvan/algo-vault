class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> numMap;
        set<int> unique;

        for (int i = 0; i < arr.size(); ++i) {
            numMap[arr[i]]++;
        }

        for (auto pair : numMap) {
            if (unique.find(pair.second) != unique.end()) {
                return false;
            }

            unique.insert(pair.second);
        }

        return true;
    }
};
