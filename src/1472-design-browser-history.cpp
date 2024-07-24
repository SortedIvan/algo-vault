struct BrowserNode {
    BrowserNode* next;
    BrowserNode* prev;
    std::string value;
    BrowserNode(std::string _value) {
        prev = nullptr;
        next = nullptr;
        value = _value;
    }
};

class BrowserHistory {
private:
    BrowserNode* head;

public:
    BrowserHistory(string homepage) {
        head = new BrowserNode(homepage);
    }
    
    void visit(string url) {
        head->next = new BrowserNode(url);
        head->next->prev = head;
        head = head->next;
    }
    
    string back(int steps) {
        return tryGoBack(0, steps, head);
    }
    
    string tryGoBack(int counter, int steps, BrowserNode* node) {
        if (!node) {
            return "";
        }
        
        if (counter == steps) {
            head = node;
            return node->value;
        }

        if (node->prev == nullptr) {
            head = node;
            return node->value;
        }

        return tryGoBack(counter + 1, steps, node->prev);
    }

    string forward(int steps) {
        return tryGoForward(0, steps, head);
    }

    string tryGoForward(int counter, int steps, BrowserNode* node) {
        if (!node) {
            return "";
        }

        if (counter == steps) {
            head = node;
            return node->value;
        }

        if (node->next == nullptr) {
            head = node;
            return node->value;
        }

        return tryGoForward(counter + 1, steps, node->next);
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
