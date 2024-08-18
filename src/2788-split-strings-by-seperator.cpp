class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;

        for (auto word : words) {
            string currWord = "";
            
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] == separator) {
                    if (!currWord.empty()) {
                        result.push_back(currWord);
                        currWord = "";
                    }
                } else {
                    currWord += word[i];
                }
            }

            if (!currWord.empty()) {
                result.push_back(currWord);
            }
        }

        return result;
    }
};
