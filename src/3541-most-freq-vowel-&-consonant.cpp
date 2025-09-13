class Solution {
public:
    int maxFreqSum(string s) {
        // given is string s with letters a to z
        std::vector<int> frequencyMap = std::vector<int>(26);
        std::unordered_set<char> vowels = std::unordered_set<char>{
            'a', 'e', 'i', 'o', 'u'
        };

        for (int i = 0; i < s.size(); ++i) {
            frequencyMap[convertToIndex(s[i])]++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        for (int i = 0; i < frequencyMap.size(); ++i) {
            const char currChar = char(i + 97);
        
            if (vowels.find(currChar) != vowels.end()) {
                maxVowel = std::max(frequencyMap[i], maxVowel);
            }
            else {
                maxConsonant = std::max(frequencyMap[i], maxConsonant);
            }
        }

        return maxVowel + maxConsonant;
    }
    
    int convertToIndex(char x) {
        return (int)x - 97;
    }
};
