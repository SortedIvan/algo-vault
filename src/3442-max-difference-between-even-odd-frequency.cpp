class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> characterCounter;

        int maxOdd = std::numeric_limits<int>::min();
        int minEven = std::numeric_limits<int>::max();

        for (int i = 0; i < s.size(); ++i) {
            characterCounter[s[i]]++;
        }

        for (const auto entry : characterCounter) {
            if (entry.second % 2 == 0) {
                // even case
                minEven = std::min(minEven, entry.second);
            }   
            else {
                // odd case
                maxOdd = std::max(maxOdd, entry.second);
            }
        }

        return maxOdd - minEven;
    }
};
