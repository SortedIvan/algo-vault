class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        if (s == goal) {
            return true;
        }
        
        int rotationCount = 0;
        int maxAllowed = goal.size();

        while (rotationCount < maxAllowed) {
            if (s == goal) {
                return true;
            }

            char temp = s[0];
            s.erase(s.begin());
            s.push_back(temp);
            rotationCount++;
        }
        
        return false;
    }
};
