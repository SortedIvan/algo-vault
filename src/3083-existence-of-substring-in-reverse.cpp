class Solution {
public:
    bool isSubstringPresent(string s) {
        /*
            given s, 
            x = substring(s), len(x) == 2
            reverse(x) == substring(s)

            abcd = ab, bc, cd
            dcba = dc, cb, ba

        */

        unordered_set<string> substrings;

        for (int i = 0; i < s.size() - 1; ++i) {
            std::string entry = string(1, s[i]);
            entry.push_back(s[i+1]);
            substrings.insert(entry);
        }

        for (int i = s.size() - 1; i >= 1; i--) {
            std::string entry = string(1, s[i]);
            entry = entry + s[i - 1];

            if (substrings.find(entry) != substrings.end()) {
                return true;
            }
        }

        return false;
    }
};
