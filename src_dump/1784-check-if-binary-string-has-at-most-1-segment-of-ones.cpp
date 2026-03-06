class Solution {
public:
    bool checkOnesSegment(string s) {
        bool foundOne = false;
        bool foundZeroAfterOne = false;

        for (int i = 0; i < s.size(); ++i) {
            if (foundOne && s[i] == '0') {
                foundZeroAfterOne = true;
                continue;
            } 

            if (s[i] == '1') {
                foundOne = true;
            }

            if (foundOne && foundZeroAfterOne && s[i] == '1') {
                return false;
            }
            
        }

        return true;
    }
};
