class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> givenWord(26);
        vector<int> currWord(26);
        vector<int> anagramIndices;
        int givenWordSize = p.size();
        int currWordSize = 0;
        int left = 0;
        int right = 0;

        for (int i = 0; i < 26; ++i) {
            givenWord[i] = 0;
            currWord[i] = 0;
        }

        for (const auto& c : p) {
            givenWord[c - 'a']++;
        }

        while (right < s.size() && left < s.size()) {
            int currCharIndex = s[right] - 'a';
            currWord[currCharIndex]++;
            currWordSize++;
            right++;

            if (currWordSize == givenWordSize && currWord == givenWord) {
                anagramIndices.push_back(left);
                currWordSize--;
                currWord[s[left] - 'a']--;
                left++;
            }
            else if (currWordSize < givenWordSize) {
                continue;
            } else {
                currWordSize--;
                currWord[s[left] - 'a']--;
                left++;
            }
        }

        return anagramIndices;
    }
};
