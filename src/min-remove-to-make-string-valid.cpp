#include <stack>
#include <vector>
#include <utility>

class Solution {
public:
    string minRemoveToMakeValid(string s) {

        std::vector<int> ignore;
        std::stack<int> braces;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == ')' && braces.empty()) {
                ignore.push_back(i);
                continue;
            }

            if (s[i] == ')' && s[braces.top()] == '(') {
                braces.pop();
                continue;
            }

            if (s[i] == '(') {
                braces.push(i);
            }
        }

        while (!braces.empty()){
            ignore.push_back(braces.top());
            braces.pop();
        }

        std::sort(ignore.begin(), ignore.end());

        int ignorePointer = 0;

        std::string result = "";

        for (int i = 0; i < s.size(); i++) {

            if (ignorePointer >= ignore.size()) {
                result += s[i];
                continue;
            }

            if (i == ignore[ignorePointer]) {
                ignorePointer++;
                continue;
            }

            result += s[i];
        }

        return result;

    }
};
