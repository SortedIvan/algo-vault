class Solution {
public:
    bool isPalindrome(string s) {
        int leftPointer = 0;
        int rightPointer = s.size() - 1;

        if (s.size() == 1)
        {
            return true;
        }

        while (leftPointer < rightPointer){
            bool leftIsChar = (s[leftPointer] >= 65 && s[leftPointer] <=90) || (s[leftPointer] >= 97 && s[leftPointer] <=122) || (s[leftPointer] <= 57 && s[leftPointer] >= 48);
            bool rightIsChar = (s[rightPointer] >= 65 && s[rightPointer] <=90) || (s[rightPointer] >= 97 && s[rightPointer] <=122)
            || (s[rightPointer] <= 57 && s[rightPointer] >= 48);

            if (!leftIsChar)
            {
                leftPointer++;
                std::cout << "?";
                continue;
            }

            if (!rightIsChar)
            {
                rightPointer--;
                continue;
            }

            if (tolower(s[leftPointer]) != tolower(s[rightPointer]))
            {
                return false;
            }

            leftPointer++;
            rightPointer--;
        }

        return true;
    }
};
