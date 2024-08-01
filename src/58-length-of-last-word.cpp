class Solution {
public:
    int lengthOfLastWord(string s) {
        int pointer = s.size() - 1;
        int counter = 0;

        // first, get rid of any trailing spaces
        while (pointer >= 0 && s[pointer] == ' ') {
            pointer--;
        }

        while (pointer >= 0 && s[pointer] != ' ') {
            pointer--;
            counter++;
        }

        return counter;
    }
};
