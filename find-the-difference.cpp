class Solution {
public:
    char findTheDifference(string s, string t) {
        std::map<char, int> sMap;
        std::map<char, int> tMap;

        for (int i = 0; i < s.size(); i++) {
            if (sMap.find(s[i]) != sMap.end()) {
                sMap[s[i]] = sMap[s[i]] + 1;
            }
            else {
                sMap.insert({s[i], 1});
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (tMap.find(t[i]) != tMap.end()) {
                tMap[t[i]] = tMap[t[i]] + 1;
            }
            else {
                tMap.insert({t[i], 1});
            }
        }

        for (auto i = tMap.begin(); i != tMap.end(); ++i) {
        cout << i->first << ": " << i->second << endl;
            if (sMap.find(i->first) != sMap.end()) {
                if (sMap[i->first] != i->second) {
                    return i->first;
                }
                continue;
            }
            else {
                return i->first;
            }
        }

        return '0';
    }
};
