class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        map<int, vector<string>> resMap;

        for (int i = 0; i < words.size(); ++i) {
            freqMap[words[i]]++;
        }

        for (const auto entry : freqMap) {
            resMap[entry.second].push_back(entry.first);
        }

        vector<string> res;

        for (auto iter = resMap.rbegin(); iter != resMap.rend() && k > 0; ++iter) {
            std::sort(iter->second.begin(), iter->second.end());

            for (const auto& word : iter->second) {
                if (k-- > 0) {
                    res.push_back(word);
                } else {
                    break;
                }
            }
        }

        return res;
    }
};

// =====================================================================================================

struct PrefixNode {
    unordered_map<char, PrefixNode*> nodeMap;
    bool isWord = false;
    int counter = 0;
};

class Solution {
private:
    PrefixNode* root = nullptr;

    // Custom comparator for priority queue
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            // If frequencies are different, compare by frequency (higher frequency first)
            if (a.first != b.first) {
                return a.first < b.first;  // Higher frequency has priority
            }
            // If frequencies are the same, compare lexicographically (smaller lexicographically first)
            return a.second > b.second;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        root = new PrefixNode();
        for (int i = 0; i < words.size(); ++i) {
            insertIntoTrie(words[i]);
        }

        vector<string> result;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> queue;

        collectTopKFrequents(root, "", queue);

        // Extract the top K words
        while (k > 0 && !queue.empty()) {
            result.push_back(queue.top().second);
            queue.pop();
            k--;
        }

        return result;
    }

    void collectTopKFrequents(PrefixNode* root, string currentStr, priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>& queue) {
        if (!root) {
            return;
        }

        if (root->isWord) {
            queue.push({root->counter, currentStr});
        }

        for (auto entry : root->nodeMap) {
            collectTopKFrequents(entry.second, currentStr + entry.first, queue);
        }
    }

    void insertIntoTrie(const string& word) {
        int pointer = 0;
        insertHelper(root, word, pointer);
    }

    void insertHelper(PrefixNode*& root, string word, int& pointer) {
        if (!root) {
            return;
        }

        if (pointer == word.size()) {
            root->isWord = true;
            root->counter++;
            return;
        }

        char currentChar = word[pointer];

        if (root->nodeMap.find(currentChar) != root->nodeMap.end()) {
            pointer++;
            insertHelper(root->nodeMap[currentChar], word, pointer);
        } else {
            pointer++;
            PrefixNode* newEntry = new PrefixNode();
            root->nodeMap[currentChar] = newEntry;
            insertHelper(root->nodeMap[currentChar], word, pointer);
        }
    }
};
