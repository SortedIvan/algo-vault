class Solution {
public:
    string generateTag(string caption) {

        // first, clean up all non english characters and de-capitalize
        // 65-90, 97-122
        vector<string> words;
        string currWord;

        for (int i = 0; i < caption.size(); ++i) {
            if (caption[i] == ' ') {
                if (!currWord.empty()) {
                    words.push_back(currWord);
                }

                currWord = "";
                continue;
            }

            int asciiCode = int(caption[i]);
            if (asciiCode < 65 || 
                (asciiCode > 90 && asciiCode < 97) ||
                asciiCode > 122) {
                // non alphabetic character, delete
                continue;
            }

            currWord += std::tolower(caption[i]);
        }
        
        if (!currWord.empty()) {
            words.push_back(currWord);
        }

        string result = "#";

        if (words.empty()) {
            return result;
        }

        result += words[0];

        for (int i = 1; i < words.size(); ++i) {
            if (result.size() > 100) {
                break;
            }

            words[i][0] = std::toupper(words[i][0]);
            result += words[i];
        }
        
        string finalResult = "";

        for (int i = 0; i < 100; ++i) {
            
            if (i >= result.size()) {
                break;
            }

            finalResult += result[i];
        }

        return finalResult;
    }
};
