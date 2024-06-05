class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        if (words.size() == 0) {
            return vector<string>();
        }

        if (words.size() == 1) {
            return words;
        }

        vector<map<char,int>> characterMap;

        for (int i = 0; i <  words.size(); i++) {
            
            map<char,int> word;

            for (int j = 0; j < words[i].size(); j++) {
                if (word.find(words[i][j]) != word.end()) {
                    word[words[i][j]]++;
                } else {
                    word.insert({words[i][j], 1});
                }
            }

            characterMap.push_back(word);
        }

        std::vector<string> result;

        for (int i = 97; i < 123; i++) {
            
            char toCheck = (char)i;
            int minimumAmountToAdd = INT_MAX;
            bool add = true;

            for (int k = 0; k < characterMap.size(); k++) {
                if (characterMap[k].find(toCheck) != characterMap[k].end()) {
                    minimumAmountToAdd = std::min(minimumAmountToAdd, characterMap[k][toCheck]);
                }
                else {
                    add = false;
                    break;
                }
            }

            if (add) {
                for (int z = 0; z < minimumAmountToAdd; z++) {
                    std::string s(1, toCheck);
                    result.push_back(s);            
                }
            }
        }

        return result;

    }
};
