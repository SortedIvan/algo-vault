class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Solution {
private:
    TrieNode* head;

public:
    string longestCommonPrefix(vector<string>& strs) {
        // 1. Build the trie
        head = new TrieNode();

        for (int i = 0; i < strs.size(); ++i) {
            
            if (strs[i] == "") {
                return "";
            } 

            int wordPointer = 0;
            addWordToTrie(wordPointer, strs[i], head);
        }

        // 2. Traverse the trie and keep track if any node has more than one child
        string prefix = "";
        collectLongestCommonPrefix(head, prefix);
        
        return prefix;
    }

    void collectLongestCommonPrefix(TrieNode* head, string& prefix) {
        if (!head) {
            return;
        }

        if (head->children.size() == 0) {
            return;
        }

        if (head->children.size() > 1) {
            return;
        }

        if (head->isWord && head->children.size() == 1) {
            return;
        }

        auto node = head->children.begin();
        prefix += node->first;
        collectLongestCommonPrefix(node->second, prefix);
    }

    void addWordToTrie(int wordPointer, string word, TrieNode* head) {
        if (wordPointer >= word.size()) {
            head->isWord = true;
            return;
        }

        char currentChar = word[wordPointer];

        // if the character already exists, dont insert, only continue down the line
        if (head->children.find(currentChar) != head->children.end()) {
            addWordToTrie(wordPointer + 1, word, head->children[currentChar]);
        } else {
            TrieNode* newNode = new TrieNode();
            head->children.insert({currentChar, newNode});
            addWordToTrie(wordPointer + 1, word, newNode);
        }

    }
};
