
#include <map>

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {

        std::map<char, int> charactersInPlate;
        std::string smallestWord = "";
        bool sufficient = false;

        for (int i = 0; i < licensePlate.size(); i++) {

            if (isdigit(licensePlate[i])) {
                continue;
            }
            if (charactersInPlate.find(tolower(licensePlate[i])) == charactersInPlate.end()) {
                if (licensePlate[i] == ' ') {
                    continue;
                }

                charactersInPlate.insert({tolower(licensePlate[i]), 1});
            }
            else {
                charactersInPlate[tolower(licensePlate[i])] = charactersInPlate[tolower(licensePlate[i])] + 1; 
            }
        }

        for (auto word : words) {
            std::map<char,int> wordMapper;

            for (int i = 0; i < word.size(); i++) {
                if (wordMapper.find(word[i]) != wordMapper.end()) {
                    wordMapper[word[i]] = wordMapper[word[i]] + 1;
                }
                else {
                    wordMapper.insert({word[i], 1});
                }
            }

            bool sufficient = true;
            for (auto i = charactersInPlate.begin(); i != charactersInPlate.end(); ++i) {

                if (wordMapper.find(i->first) == wordMapper.end()) {
                    sufficient = false;
                    break;
                }

                if (wordMapper[i->first] < i->second) {
                    sufficient = false;
                    break;
                }
            }

            if (sufficient) {
                if (smallestWord.size() == 0 || smallestWord.size() > word.size()) {
                    smallestWord = word;
                }
            }
        }

        return smallestWord;
    }
};
