class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> occuranceArr(26);
        for (int i = 0; i < 26; ++i) {
            occuranceArr[i] = -1;
        }

        for (int i = 0; i < s.size(); ++i) {
            int cIndex = s[i] - 97;
            if (occuranceArr[cIndex] == -1) {
                occuranceArr[cIndex] = i + 1;
            } else {
                occuranceArr[cIndex] = (i + 1) - occuranceArr[cIndex];
            }
        }

        for (int i = 0; i < 25; i++) {
            std::cout << occuranceArr[i] - 1 << std::endl;
        }

        for (int i = 0; i < distance.size(); ++i) {
            if (occuranceArr[i] >= 0) {
                if (occuranceArr[i] - 1 != distance[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};
