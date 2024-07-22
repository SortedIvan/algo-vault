class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> mapping1;
        unordered_map<char, char> mapping2;

        int pointer = 0;
        while (pointer < s.size()) {
            
            if (mapping1.find(s[pointer]) != mapping1.end()) {
                if (mapping1[s[pointer]] != t[pointer]) {
                    return false;
                }
            }

            if (mapping2.find(t[pointer]) != mapping2.end()) {
                if (mapping2[t[pointer]] != s[pointer]) {
                    return false;
                }
            }

            if (mapping1.find(s[pointer]) == mapping1.end()) {
                mapping1.insert({s[pointer], t[pointer]});
            }

            if (mapping2.find(t[pointer]) == mapping2.end()) {
                mapping2.insert({t[pointer], s[pointer]});
            }

            int count1 = countSequence(pointer, s[pointer], s);
            int count2 = countSequence(pointer, t[pointer], t);

            if (count1 != count2) {
                return false;
            }

            pointer += count1;
        }

        return true;
    }

    int countSequence(int pointer, char currChar, std::string s) {
        int counter = 0;
        while (pointer < s.size() && currChar == s[pointer]) {
            pointer++;
            counter++;
        }
        return counter;
    }
};
