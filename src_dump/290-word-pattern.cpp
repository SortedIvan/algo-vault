class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        unordered_map<char, string> wordMap;
        set<string> used;
        int leftPointer = 0;
        int rightPointer = 0;

        std::stringstream ss(s);
        std::string item;

        while (getline(ss, item, ' ')) {
            words.push_back(item);
        }

        if (words.size() != pattern.size()) {
            return false;
        }

        while (leftPointer < pattern.size() && rightPointer < s.size()) {
            if (wordMap.find(pattern[leftPointer]) != wordMap.end()) {
                if (wordMap[pattern[leftPointer]] != words[rightPointer]) {
                    return false;
                }
            } else {
                if (used.contains(words[rightPointer])) {
                    return false;
                }

                used.insert(words[rightPointer]);
                wordMap.insert({pattern[leftPointer], words[rightPointer]});
            }

            leftPointer++;
            rightPointer++;
        }

        return true;
    }
}; 
