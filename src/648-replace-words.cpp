class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        std::map<std::string, int> words;

        for (int i = 0; i < dictionary.size(); i++) {
            words.insert({dictionary[i], 1});
        }

        std::string tmp; 
        stringstream ss(sentence);
        std::vector<std::string> split;

        std::string result = "";

        while(getline(ss, tmp, ' ')){
            split.push_back(tmp);
        }

        for (int k = 0; k < split.size(); k++) {
            
            std::string prefix = "";
            bool found = false;

            for (int i = 0; i < split[k].size(); ++i) {
                prefix += split[k][i];

                if (words.find(prefix) != words.end()) {
                    result += prefix;
                    found = true;
                    break;
                }
            }

            if (!found) {
                result += split[k];
            }

            if (k != split.size() - 1) {
                result += " ";
            }
        } 

        return result;
    }
};
