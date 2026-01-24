class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char> characters;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                
                string word = "";
                
                while (!characters.empty()) {
                    char top = characters.top();
                    characters.pop();

                    if (top == '(') {
                        break;
                    }

                    word = top + word;
                }

                for (int k = word.size() - 1; k >= 0; --k) {
                    characters.push(word[k]);
                } 
            } else {
                characters.push(s[i]);
            }
        }

        string finalWord = "";

        while (!characters.empty()) {
            finalWord.push_back(characters.top());
            characters.pop();
        }

         reverse(finalWord.begin(), finalWord.end());

        return finalWord;
    }
};
