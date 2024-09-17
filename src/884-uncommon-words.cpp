#include <sstream> 

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCounter;
        vector<string> uncommonWords;

        vector<string> w1;
        vector<string> w2;

        convertStringToArr(w1, s1);
        convertStringToArr(w2, s2);

        for (const string word : w1) {
            wordCounter[word]++;
        }

        for (const string word : w2) {
            wordCounter[word]++;
        }

        for (const auto& word : wordCounter) {
            if (word.second == 1) {
                uncommonWords.push_back(word.first);
            }
        }
        
        return uncommonWords;
    }

    void convertStringToArr(vector<string>& words, string word) {
        string toAdd = "";
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ' ') {
                words.push_back(toAdd);
                toAdd = "";
                continue;
            }

            toAdd += word[i];
        }

        if (toAdd.size() > 0) {
            words.push_back(toAdd);
        }
    }
};
