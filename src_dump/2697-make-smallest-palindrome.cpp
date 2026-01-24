class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int leftPointer = 0;
        int rightPointer = s.size() - 1;

        while (leftPointer < rightPointer) {
            if (s[leftPointer] != s[rightPointer]) {
                if (s[leftPointer] > s[rightPointer]) {
                    s[leftPointer] = s[rightPointer];
                } else {
                    s[rightPointer] = s[leftPointer];
                }   
            }
            leftPointer++;
            rightPointer--;
        }

        return s;
    }
};
