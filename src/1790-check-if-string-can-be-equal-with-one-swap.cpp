class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char, int> s1Map;
        unordered_map<char, int> s2Map;

        int s1Count = 0;
        int s2Count = 0;

        for (int i = 0; i < s1.size(); ++i) {
            s1Map[s1[i]]++;
            s1Count++;
        }

        for (int k = 0; k < s2.size(); ++k) {
            s2Map[s2[k]]++;
            s2Count++;
        }

        for (auto const& x : s1Map)
        {
            // take a random character from one of the maps
            char a = x.first;

            // compare the count of the same character in the other map
            if (s2Map.find(a) == s2Map.end() || x.second != s2Map[a]) {
                return false;
            }

            s1Count -= x.second;
            s2Count -= s2Map[a];
        }

        if (s1Count != s2Count) {
            return false;
        }

        int swappedTimes = 0;
        int wordPointer = 0;

        while (wordPointer < s1.size()) {
            if (s1[wordPointer] != s2[wordPointer]) {
                
                if (swappedTimes > 2) {
                    return false;
                }

                swappedTimes++;
                wordPointer++;
                continue;
            }

            wordPointer++;
        }

        return (swappedTimes == 0) || (swappedTimes == 2);
    }
};
