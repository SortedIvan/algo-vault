class MyHashSet {
private:
    vector<int> table;
public:
    MyHashSet() {

    }
    
    void add(int key) {
        auto res = binarySearch(key);

        if (!res.second) {
            table.insert(table.begin() + res.first, key);
        }
    }
    
    void remove(int key) {
        auto res = binarySearch(key);
        if (res.second) {
            table.erase(table.begin() + res.first);
        }
    }
    
    bool contains(int key) {
        return binarySearch(key).second;
    }

    pair<int,bool> binarySearch(int key) {
        int left = 0;
        int right = table.size() - 1;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (table[mid] == key) {
                return {mid, true};
            }

            if (table[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {left, false};
    }

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
