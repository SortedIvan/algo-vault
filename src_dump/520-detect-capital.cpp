class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalLetterCounter = 0;
        
        for (int i = 0; i < word.size(); ++i) {
            if (isCapital(word[i])) {
                capitalLetterCounter++;
            }
        }

        if (capitalLetterCounter == word.size() || !capitalLetterCounter || (capitalLetterCounter == 1 && isCapital(word[0]))) {
            return true;
        }

        return false;
    }

    bool isCapital(char character) {
        return (int)character >= 65 && (int)character <= 90;
    }
};
