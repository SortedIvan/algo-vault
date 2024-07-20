class Solution {
public:
    string removeStars(string s) {
        stack<char> starStack;
        int pointer = 0;

        while (pointer < s.size()) {
            if (s[pointer] == '*') {
                if (!starStack.empty()) {
                    if (starStack.top() != '*') {
                        starStack.pop();
                    }
                } else {
                    starStack.push('*');
                }
            } else {
                starStack.push(s[pointer]);
            }

            pointer++;
        }

        std::string result = "";

        while (!starStack.empty()) {
            result.push_back(starStack.top());
            starStack.pop();
        }
        
        std::reverse(result.begin(), result.end());

        return result;
    }
};
