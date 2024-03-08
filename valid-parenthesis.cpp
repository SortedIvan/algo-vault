#include <stack>

class Solution {
public:
    static const char OPEN_CIRCLE = '(';
    static const char CLOSE_CIRCLE = ')';
    static const char OPEN_SQUARE = '[';
    static const char CLOSE_SQUARE = ']';
    static const char OPEN_CURLY = '{';
    static const char CLOSE_CURLY = '}';

    bool isValid(string s) {
        std::stack<char> pars;
        int pointer = 0;

        if (s.size() == 1) {
            return false;
        }
        
        while (pointer < s.size()) {
            if (pointer == 0) {
                pars.push(s[pointer]);
                pointer++;
                continue;
            }

            if (s[pointer] == OPEN_CIRCLE || s[pointer] == OPEN_SQUARE || s[pointer] == OPEN_CURLY) {
                pars.push(s[pointer]);
                pointer++;
                continue;
            }

            if (pars.empty()) {
                return false;
            }

            if (s[pointer] == CLOSE_CIRCLE) {
                if (pars.top() != OPEN_CIRCLE) {
                    return false;
                }
                pars.pop();
                pointer++;
                continue;
            }


            if (s[pointer] == CLOSE_SQUARE) {  
                if (pars.top() != OPEN_SQUARE) {
                    return false;
                }
                pars.pop();
                pointer++;
                continue;
            }


            if (s[pointer] == CLOSE_CURLY) {
                if (pars.top() != OPEN_CURLY) {
                    return false;
                }
                pars.pop();
                pointer++;
                continue;
            }

        }

        if (pars.size() > 0) {
            return false;
        }

        return true;

    }
};
