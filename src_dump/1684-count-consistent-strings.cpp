class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allowedChars[26] = {false};
        for (int i = 0; i < allowed.size(); ++i) {
            allowedChars[allowed[i] - 'a'] = true;
        }

        int correctWords = 0;
        
        for (const auto& word : words) {
            bool wordChars[26] = {false};
            
            for (int i = 0; i < word.size(); ++i) {
                wordChars[word[i] - 'a'] = true;
            }

            bool wordIsCorrect = true;
            for (int k = 0; k < 26; ++k) {
                if (wordChars[k] && !allowedChars[k]) {
                    wordIsCorrect = false;
                    break;
                }
            }

            if (wordIsCorrect) {
                correctWords++;
            }
        }

        return correctWords;
    }
};
