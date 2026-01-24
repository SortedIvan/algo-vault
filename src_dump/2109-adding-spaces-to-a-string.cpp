class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int spacesPointer = 0;
        int stringPointer = 0;

        while (stringPointer < s.size() && spacesPointer < spaces.size()) {
            if (stringPointer == spaces[spacesPointer]) {
                result += " ";
                result += s[stringPointer];
                spacesPointer++;
                stringPointer++;
            }
            else {
                result += s[stringPointer];
                stringPointer++;
            }
        }

        while (stringPointer < s.size()) {
            result += s[stringPointer];
            stringPointer++;
        }

        return result;
    }
};
