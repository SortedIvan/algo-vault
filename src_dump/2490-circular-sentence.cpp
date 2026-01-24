class Solution {
public:
    bool isCircularSentence(string sentence) {
        // base case
        if (sentence[0] != sentence[sentence.size() - 1]) {
            return false;
        }

        int pointer = 0;
        char prevChar;
        while (pointer < sentence.size()) {
            if (sentence[pointer] == ' ') {
                if (sentence[pointer + 1] != prevChar) {
                    return false;
                }
            }
            else {
                prevChar = sentence[pointer];
            }

            pointer++;
        }

        return true;
    }
};
