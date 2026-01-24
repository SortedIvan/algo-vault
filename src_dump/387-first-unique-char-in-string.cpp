class Solution {
public:
    int firstUniqChar(string s) {
        int charMap[26];

        for (int i = 0; i < 26; ++i) {
            charMap[i] = -1;
        }


        for (int i = 0; i < s.size(); ++i) {
            int index = s[i] - 97;

            if (charMap[index] == -2) {
                continue;
            }

            if (charMap[index] != -1) {
                charMap[index] = -2;
            }
            else {
                charMap[index] = i;
            }
        }

        int firstOccurance = std::numeric_limits<int>::max();

        for (int i = 0; i < 26; ++i) {
            if (charMap[i] == -2) {
                continue;
            }

            if (charMap[i] == -1) {
                continue;
            }
            
            firstOccurance = std::min(firstOccurance, charMap[i]);
        }
        
        if (firstOccurance == std::numeric_limits<int>::max()) {
            return -1;
        }

        return firstOccurance;
    }
};
