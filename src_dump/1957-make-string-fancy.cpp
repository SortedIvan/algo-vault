class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int pointer = 0;
        int counter = 0;

        while (pointer < s.size()) {
            if (result.size() == 0) {
                counter++;
                result.push_back(s[pointer]);
                pointer++;
                continue;
            }

            if (result[result.size() - 1] == s[pointer]) {
                counter++;

                if (counter == 3) {
                    pointer++;
                    counter--;
                    continue;
                }

                result.push_back(s[pointer]);
                pointer++;
            }
            else {
                counter = 1;
                result.push_back(s[pointer]);
                pointer++;
            }
        }

        return result;
    }
};
