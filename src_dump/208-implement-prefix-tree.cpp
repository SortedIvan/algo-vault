class Trie {
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    char nodeCharacter;
    bool isWord = false;

    TrieNode() {

    }
};

private:
    TrieNode* root = new TrieNode();

public:
    Trie() {
    }
    
    void insert(string word) {
        int pointer = 0;

        insertHelper(root, word, pointer);
    }

    void insertHelper(TrieNode* root, string word, int& pointer) {
        if (pointer >= word.size()) {
            root->isWord = true;
            return;
        }

        char character = word[pointer];

        if (root->children.find(character) != root->children.end()) {
            // already has this character, move on to the child node
            pointer++;
            insertHelper(root->children[character], word, pointer);
        } else {
            // no children available for the character, create a new child
            TrieNode* child = new TrieNode();
            child->nodeCharacter = character;
            root->children.insert({character, child});
            pointer++;
            insertHelper(child, word, pointer);
        }
    }

    bool wordSearchHelper(TrieNode* root, string word, int pointer) {
        if (pointer >= word.size()) {
            return root->isWord;
        }
        
        char currCharacter = word[pointer];

        if (root->children.find(currCharacter) != root->children.end()) {
            pointer++;
            return wordSearchHelper(root->children[currCharacter], word, pointer);
        } 

        return false;
    }

    bool search(string word) {
        int pointer = 0;
        return wordSearchHelper(root, word, pointer);
    }
    

    bool prefixSearchHelper(TrieNode* root, string prefix, int& pointer) {
        if (pointer >= prefix.size()) {
            return true;
        }
        
        char currentChar = prefix[pointer];

        if (root->children.find(currentChar) != root->children.end()) {
            pointer++;
            return prefixSearchHelper(root->children[currentChar], prefix, pointer);
        } 

        return false;
    }


    bool startsWith(string prefix) {
        int pointer = 0;
        return prefixSearchHelper(root, prefix, pointer);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
