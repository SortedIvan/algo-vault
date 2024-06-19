class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> wordMap;

        for (int i = 0; i < strs.size(); ++i) {
            string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());

            std::cout << sorted << std::endl;

            if (wordMap.find(sorted) != wordMap.end()) {
                wordMap[sorted].push_back(strs[i]);
            } else {
                vector<string> newVec;
                newVec.push_back(strs[i]);
                wordMap.insert({sorted, newVec});
            }
        }

        vector<vector<string>> result;

        for (auto i = wordMap.begin(); i != wordMap.end(); ++i) {
            result.push_back(i->second);
        }

        return result;
    }
};
