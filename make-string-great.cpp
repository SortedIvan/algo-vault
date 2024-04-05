#include <stack>
#include <cctype>
#include <iostream>
#include <cstring>

class Solution {
public:
    string makeGood(string s) {
        std::stack<char> characters;

        if (s.size() == 1)
        {
            return s;
        }

        for (int i = 0; i < s.size(); i++) 
        { 
            if (characters.size() == 0) {
                characters.push(s[i]);
                continue;
            }
            char copy = s[i];
            char copy2 = characters.top();

            if (tolower(copy) == tolower(copy2)) {
                if (isupper(s[i]) && !isupper(characters.top())) {
                    characters.pop();
                    continue;
                }
                else if (!isupper(s[i]) && isupper(characters.top())) {
                    characters.pop();
                    continue;
                }
            }

            characters.push(s[i]);
        }

        std::string result = "";
        while (!characters.empty()) {
            result = characters.top() + result;
            characters.pop();
        }
        
        return result;
    }
};
