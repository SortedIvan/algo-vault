class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> charCounter;
        priority_queue<pair<int, char>> charQueue;

        for (int i = 0; i < s.size(); ++i) {
            charCounter[s[i]]++;
        }

        for (const auto entry : charCounter) {
            charQueue.push({entry.second, entry.first});
        }

        string result = "";

        while (!charQueue.empty()) {
            auto element1 = charQueue.top();
            charQueue.pop();

            if (element1.first == 1) {
                result.push_back(element1.second);
                continue;
            }

            if (element1.first > 1 && charQueue.empty()) {
                return "";
            }  

            auto element2 = charQueue.top();
            charQueue.pop();

            result.push_back(element1.second);
            result.push_back(element2.second);

            element1.first--;
            element2.first--;

            if (element1.first > 0) {
                charQueue.push(element1);
            }

            if (element2.first > 0) {
                charQueue.push(element2);
            }
        }
 
        return result;
    }
};
