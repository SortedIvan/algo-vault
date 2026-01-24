class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> firstWord;
        stack<char> secondWord;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                if (!firstWord.empty()) {
                    firstWord.pop();
                }
            } else {
                firstWord.push(s[i]);
            }
        }

        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '#') {
                if (!secondWord.empty()) {
                    secondWord.pop();
                }
            } else {
                secondWord.push(t[i]);
            }
        }

        if (secondWord.size() != firstWord.size()) {
            return false;
        }

        while (!firstWord.empty() && !secondWord.empty()) {
            if (firstWord.top() != secondWord.top()) {
                return false;
            }

            firstWord.pop();
            secondWord.pop();
        }

        return true;
    }
};
