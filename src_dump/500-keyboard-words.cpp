class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> keyboardRows = {
           {'q','w','e','r','t','y', 'u','i','o', 'p'},
           {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
           {'z', 'x', 'c', 'v', 'b', 'n', 'm'}
        };

        vector<string> result;

        // for every keyboard row
        for (int k = 0; k < keyboardRows.size(); ++k) {
            
            for (string word : words) {
                bool add = true;

                for (int i = 0; i < word.size(); ++i) {
                    char c = (char)std::tolower(word[i]);

                    if (keyboardRows[k].find(c) == keyboardRows[k].end()) {
                        

                        add = false;
                        break;
                    }
                }

                if (add) {
                    result.push_back(word);
                }

            }

        }

        return result;
    }
};
