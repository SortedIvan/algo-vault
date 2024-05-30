class Solution {
public:
    int longestPalindrome(string s) {
        int longest = 0;
        map<char, int> charMap;
        for (int i = 0; i < s.size(); i++)
        {
            if (charMap.find(s[i]) != charMap.end())
            {
                charMap[s[i]]++;
            }
            else
            {
                charMap.insert({s[i], 1});
            }
        }

        for (auto i = charMap.begin(); i != charMap.end(); ++i)
        {
            if (i->second % 2 == 0)
            {
                longest += i->second;
                i->second = 0;
            }
            else
            {
                if (i->second == 1)
                {
                    continue;
                }

                longest += (i->second - 1);
                i->second = 1;
            }
        }

        for (auto i = charMap.begin(); i != charMap.end(); ++i)
        {
            if (i->second > 0)
            {
                return longest + 1;
            }
        }

        return longest;
    }
};
