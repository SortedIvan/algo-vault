class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int pointer = 0;

        unordered_map<string, int> romanMap = {
            {"I", 1}, 
            {"V", 5}, 
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},

            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900},
        }; 

        while (pointer < s.size()) {
            if (pointer == s.size() - 1) {
                result += romanMap[std::string(1,s[pointer])];        
                break;
            }
            result += convertStringToNum(romanMap, s, pointer);
        }

        return result;
    }

    int convertStringToNum(unordered_map<string, int>& romanMap, const string& s, int& pointer) {
        int result = 0;
        string num;
        num += s[pointer];
        if (romanMap.find(num + s[pointer + 1]) != romanMap.end()) {
            num += s[pointer + 1];
            result = romanMap[num];
            pointer += 2;
            return result;
        }
        result = romanMap[num];
        pointer++;
        return result;
    }
};
