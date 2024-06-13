class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> charMap;
        int currentBiggest = 0;

        if (s.size() == 0) {
            return 0;
        } 

        if (s.size() == 1) {
            return 1;
        }

        while (right < s.size()) {
            
            if (charMap.size() > currentBiggest) {
                currentBiggest = charMap.size();
            }

            if (right == 0) {
                charMap.insert({s[right], 0});
                right++;
                continue;
            }

            if (charMap.find(s[right]) != charMap.end()) {
                charMap.erase(s[left]);
                left++;
            }
            else {
                charMap.insert({s[right], right});
                right++;
            }

            if (left == right) {
                if (left >= s.size()) {
                    break;
                }

                charMap.insert({s[left], left});
                right++;
            }
        }

        if (currentBiggest > charMap.size()) {
            return currentBiggest;
        } 
        else {
            return charMap.size();
        }

    }
};
