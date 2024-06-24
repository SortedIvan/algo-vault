class TrieNode {
public:
    TrieNode* children[26]; // 97 - 122
    bool isWord = false;
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        int wordPointer = 0;
        addWordHelper(wordPointer, word, root);
    }

    void addWordHelper(int wordPointer, string word, TrieNode* root) {
        if (wordPointer >= word.size()) {
            root->isWord = true;
            return;
        }

        char currChar = word[wordPointer];

        if (root->children[currChar - 97] != nullptr) {
            // we can recurse down with a given char
            wordPointer++;
            addWordHelper(wordPointer, word, root->children[currChar - 97]);
        } else {
            TrieNode* child = new TrieNode();
            root->children[currChar - 97] = child;
            wordPointer++;
            addWordHelper(wordPointer, word, child);
        }
    }
    
    bool search(string word) {
        int wordPointer = 0;
        return searchHelper(wordPointer, word, root);
    }

    bool searchHelper(int pointer, string word, TrieNode* root) {
        if (pointer >= word.size()) {
            return root->isWord;
        }

        char currChar = word[pointer];
        
        if (currChar == '.') {
            for (int i = 0; i < 26; ++i) {
                if (root->children[i] != nullptr) {
                    if (searchHelper(pointer + 1, word, root->children[i])) {
                        return true;
                    }
                }
            }

        } else {
            if (root->children[currChar - 97] == nullptr) {
                return false;
            }

            pointer++;
            return searchHelper(pointer, word, root->children[currChar - 97]);
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
