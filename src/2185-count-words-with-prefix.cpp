struct PrefixNode {
    bool isWord;
    int wordCount = 0;
    std::unordered_map<char, PrefixNode*> nodeMap;
};

class PrefixTree {
private:
    PrefixNode* root;
    void insertIntoPrefixTreeHelper(PrefixNode* node, int pointer, string& word) {
        if (word.size() == pointer) {
            node->isWord = true;
            node->wordCount++;
            return;
        }

        char currentChar = word[pointer];
        pointer++;

        if (node->nodeMap.find(currentChar) != node->nodeMap.end()) {
            // if the character already exists, just go down the tree (dfs continue)
            insertIntoPrefixTreeHelper(node->nodeMap[currentChar], pointer, word);
        }
        else {
            PrefixNode* newNode = new PrefixNode();
            node->nodeMap.insert({currentChar, newNode});
            insertIntoPrefixTreeHelper(newNode, pointer, word);
        }
    }

    int countLeaves(PrefixNode* root) {
        queue<PrefixNode*> bfs;
        int counter = 0;
        bfs.push(root);

        while (!bfs.empty()) {
            PrefixNode* node = bfs.front();
            bfs.pop();

            if (node->nodeMap.empty()) {
                counter += node->wordCount;
                continue;
            }

            if (node->isWord) {
                counter += node->wordCount;
            }

            for (auto entry : node->nodeMap) {
                bfs.push(entry.second);
            }
        }

        return counter;
    }

public:
    PrefixTree() {
        root = new PrefixNode();
    }

    void insertIntoPrefixTree(string& word) {
        int wordPointer = 0;
        insertIntoPrefixTreeHelper(root, wordPointer, word);
    }
    
    void findNodeByPrefix(PrefixNode* currNode, PrefixNode*& result, string& prefix, int pointer) {
        if (prefix.size() == pointer) {
            // we are in the last node
            result = currNode;
            return;
        }

        char currentChar = prefix[pointer];

        if (currNode->nodeMap.find(currentChar) == currNode->nodeMap.end()) {
            return; // nothing found
        }

        pointer++; 

        findNodeByPrefix(currNode->nodeMap[currentChar], result, prefix, pointer);
    }

    int countWordsByPrefix(string& prefix) {
        if (prefix.size() == 0) {
            return 0;
        }

        PrefixNode* result = nullptr;
        int pointer = 0;

        findNodeByPrefix(root, result, prefix, pointer);

        if (!result) {
            return 0;
        }

        return countLeaves(result);
    }
};


class Solution {
public:
    // can solve this easy way or hard way
    int prefixCount(vector<string>& words, string pref) {
        PrefixTree prefixTree;
        
        for (string& word : words) {
            prefixTree.insertIntoPrefixTree(word);
        }

        return prefixTree.countWordsByPrefix(pref);
    }
};
