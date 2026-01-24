class PrefixNode {
public:
    unordered_map<char, PrefixNode*> nodeMap;
    bool isWord;
};

class Solution {
private:
    PrefixNode* root = new PrefixNode();
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        string currPrefix = "";
        int badChars = searchWord.size();

        buildTree(products);

        for (int i = 0; i < searchWord.size(); ++i) {
            currPrefix += searchWord[i];

            vector<string> suggestions = getProductSuggestions(currPrefix);

            if (suggestions.size() == 0) {
                break;
            }

            badChars--;

            // Always sort the suggestions
            std::sort(suggestions.begin(), suggestions.end());

            if (suggestions.size() > 3) {
                suggestions.resize(3);
            }

            result.push_back(suggestions);
        }

        for (int i = 0; i < badChars; ++i) {
            result.push_back(vector<std::string>());
        }

        return result;
    }

    std::vector<std::string> getProductSuggestions(string& prefix) {
        int prefixPointer = 0;
        PrefixNode* node = getPrefixNode(root, prefix, prefixPointer);

        if (!node) {
            return std::vector<std::string>();
        } 

        std::vector<std::string> suggestions;
        collectAllChildren(suggestions, node, prefix);
        return suggestions;
    } 

    void collectAllChildren(std::vector<std::string>& suggestions, PrefixNode*& root, string currentPrefix) {
        if (!root) {
            return;
        }

        if (root->isWord) {
            suggestions.push_back(currentPrefix);
        }

        for (auto child : root->nodeMap) {
            collectAllChildren(suggestions, child.second, currentPrefix + child.first);
        }
    }

    PrefixNode* getPrefixNode(PrefixNode* root, string& prefix, int prefixPointer) {
        if (!root) {
            return nullptr;
        }
        
        if (prefix.size() == prefixPointer) {
            return root;
        }

        char currChar = prefix[prefixPointer];

        if (root->nodeMap.find(currChar) == root->nodeMap.end()) {
            return nullptr;
        }

        return getPrefixNode(root->nodeMap[currChar], prefix, prefixPointer + 1);
    }

    void buildTree(vector<string>& products) {
        for (int i = 0; i < products.size(); ++i) {
            insertWordIntoTree(products[i]);
        } 
    }

    void insertWordIntoTree(std::string& word) {
        int wordPointer = 0;
        insertWordIntoTreeHelper(word, wordPointer, root);
    }

    void insertWordIntoTreeHelper(std::string& word, int wordPointer, PrefixNode*& node) {
        if (wordPointer == word.size()) {
            node->isWord = true;
            return;
        }

        char currChar = word[wordPointer];

        if (node->nodeMap.find(currChar) != node->nodeMap.end()) {
            // char already exists, keep crawling down
            insertWordIntoTreeHelper(word, wordPointer + 1, node->nodeMap[currChar]);
        }
        else {
            PrefixNode* child = new PrefixNode();
            child->isWord = false;
            node->nodeMap.insert({currChar, child});
            insertWordIntoTreeHelper(word, wordPointer + 1, child);
        }
    }
};
