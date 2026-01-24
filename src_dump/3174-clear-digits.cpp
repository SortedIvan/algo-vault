class Solution {
public:
    string clearDigits(string s) {
        stack<char> digitStack;
        int stringPointer = 0;
        string result;

        while (stringPointer < s.size()) {
            char characterToProcess = s[stringPointer];

            if (isDigit(characterToProcess)) {
                if (digitStack.empty()) {
                    stringPointer++;
                    continue;
                }

                digitStack.pop();
                stringPointer++;
            }
            else {
                digitStack.push(characterToProcess);
                stringPointer++;
            }
        }

        while (!digitStack.empty()) {
            result = digitStack.top() + result;
            digitStack.pop();
        }

        return result;
    }

    bool isDigit(char character) {
        return ((int)character >= 48 && (int)character <= 57);
    }
};
