class Node {
public:
    Node* prev;
    Node* next;
    int val;
    int key;

    Node(int _val, int _key) : val(_val), key(_key), prev(nullptr), next(nullptr) {}
    Node() : val(0), key(0), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    map<int, Node*> nodeMap;
    int maxCap = 0;
    int curr = 0;

    void moveToTail(Node* node) {
        if (node == tail) {
            return;
        }
        if (node == head) {
            head = node->next;
            head->prev = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node;
    }

public:
    LRUCache(int capacity) {
        maxCap = capacity;
    }

    void traverseLinkedList(Node* traverse) {
        while (traverse) {
            std::cout << traverse->val << std::endl;
            traverse = traverse->next;
        }
    }

    int get(int key) {
        if (nodeMap.find(key) != nodeMap.end()) {
            Node* node = nodeMap[key];
            moveToTail(node);
            return node->val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (nodeMap.find(key) != nodeMap.end()) {
            Node* node = nodeMap[key];
            node->val = value;
            moveToTail(node);
            return;
        }

        Node* insert = new Node(value, key);
        
        if (curr < maxCap) {
            if (curr == 0) {
                head = insert;
                tail = insert;
            } else {
                tail->next = insert;
                insert->prev = tail;
                tail = insert;
            }
            nodeMap[key] = insert;
            curr++;
        } else { // delete LRU here
            nodeMap.erase(head->key);
            if (head == tail) {
                delete head;
                head = insert;
                tail = insert;
            } else {
                Node* oldHead = head;
                head = head->next;
                head->prev = nullptr;
                delete oldHead;
                tail->next = insert;
                insert->prev = tail;
                tail = insert;
            }
            nodeMap[key] = insert;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
