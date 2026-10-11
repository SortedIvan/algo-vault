class Solution {
public:
    string removeOuterParentheses(string s) {
        if (s.empty()) { return s;}
        std::vector<std::string> primitiveSplitList;

        int LEFT_PAR_COUNT = 0;
        int RIGHT_PAR_COUNT = 0;
        std::string currentPrimitiveSplitString;

        for (int i = 0; i < s.size(); ++i) {
            if (LEFT_PAR_COUNT == RIGHT_PAR_COUNT && LEFT_PAR_COUNT != 0) {
                primitiveSplitList.push_back(currentPrimitiveSplitString);
                currentPrimitiveSplitString = "";
                LEFT_PAR_COUNT = 0;
                RIGHT_PAR_COUNT = 0;
            }

            if (s[i] == '(') {
                LEFT_PAR_COUNT++;
            }
            else {
                RIGHT_PAR_COUNT++;
            }

            currentPrimitiveSplitString += s[i];
        }

        if (LEFT_PAR_COUNT == RIGHT_PAR_COUNT && LEFT_PAR_COUNT != 0 && !currentPrimitiveSplitString.empty()) {
            primitiveSplitList.push_back(currentPrimitiveSplitString);
        }

        std::string result;

        for (const auto& part : primitiveSplitList) {
            if (part.size() == 2) {
                continue;
            }
            
            std::string newPart;
            newPart.reserve(part.size() - 2);

            for (int k = 1; k < part.size() - 1; ++k) {
                newPart += part[k];
            }

            result += newPart;
        }

        return result; 
    }
};
