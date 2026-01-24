class NumberContainers {
private:
    std::map<int, std::set<int>> container;
    std::unordered_map<int,int> indexMap;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indexMap.find(index) == indexMap.end()) {
            indexMap.insert({index,number});
            container[number].insert(index);
            return;
        }

        int foundNumber = indexMap[index];
        container[foundNumber].erase(index);

        if (container[foundNumber].empty()) {
            container.erase(foundNumber);
        }
        
        indexMap[index] = number;
        container[number].insert(index);
    }
    
    int find(int number) {
        if (container.find(number) == container.end()) {
            return -1;
        }
        return *container[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
