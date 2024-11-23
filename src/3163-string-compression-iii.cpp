class Solution {
public:
    string compressedString(string word) {
        string result;
        int pointer = 0;

        while (pointer < word.size()) {
            int innerPointer = pointer;
            char currChar = word[pointer];
            int counter = 0;

            while (word[innerPointer] == currChar && counter != 9) {
                counter++;
                innerPointer++;
            }

            result += std::to_string(counter);
            result += currChar;
            pointer = innerPointer;
        }

        return result;
    }
};
