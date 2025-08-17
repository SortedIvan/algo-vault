class Solution {
public:
    int maximum69Number (int num) {
        // 9669 % 10 = 966, remainder 9
        // 966 % 10 = 96,  remainder 6
        // 96 % 10 = 9, remainder 6
        // 9 % 10 = 9

        if (num < 10) {
            return 9;
        }

        int maxPossibleNumber = std::numeric_limits<int>::min();
        string currentNumber = std::to_string(num);

        for (int i = 0; i < currentNumber.size(); ++i) {
            char temporary = currentNumber[i];
            maxPossibleNumber = std::max(std::stoi(currentNumber), maxPossibleNumber);
            currentNumber[i] = swapCharacter(temporary);
            maxPossibleNumber = std::max(std::stoi(currentNumber), maxPossibleNumber);

            // reset back
            currentNumber[i] = temporary;
        }

        return maxPossibleNumber;
    }

    char swapCharacter(char input) {
        if (input == '6') {
            return '9';
        }

        return '6';
    }
};
