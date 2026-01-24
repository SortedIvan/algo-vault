class Solution {
public:
    int countLargestGroup(int n) {
        int biggestGroupSize = 0;
        int result = 0;
        std::unordered_map<int, int> groupCounter;

        for (int i = 1; i < n + 1; ++i) {
            int digits = sumDigits(i);
            groupCounter[digits]++;
            biggestGroupSize = std::max(biggestGroupSize, groupCounter[digits]);
        }

        for (const auto pair : groupCounter) {
            if (pair.second == biggestGroupSize) {
                result++;
            }
        }

        return result;
    }

    int sumDigits(int number) {
        int digitSum = 0;
        while (number > 9) {
            int digit = number % 10;
            digitSum += digit;
            number = number / 10;
        }

        digitSum += number;
        return digitSum;
    } 
};
