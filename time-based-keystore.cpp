#include <map>
#include <vector>
#include <utility>
#include <string>

class TimeMap {
public:

    std::map<std::string, std::vector<std::pair<int, std::string>>> keystore;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (keystore.find(key) == keystore.end()) {

            std::vector<std::pair<int, std::string>> toPush;
            std::pair<int, std::string> pair = std::make_pair(timestamp, value);
            toPush.push_back(pair);

            keystore.insert({key, toPush});
        }
        else {
            std::pair<int, std::string> pair = std::make_pair(timestamp, value);
            keystore[key].push_back(pair);
        }
    }
    
    string get(string key, int timestamp) {
        if (keystore.find(key) == keystore.end()) {
            return "";
        }

        return searchPair(keystore[key], timestamp);
    }

    std::string searchPair(std::vector<std::pair<int, std::string>>& pairs, int target) {
        if (pairs[pairs.size() - 1].first <= target) {
            return pairs[pairs.size() - 1].second;
        }
        // otherwise, we have to search for it

        int left = 0;
        int right = pairs.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;

            if (pairs[mid].first == target) {
                return pairs[mid].second;
            }

            if (pairs[mid].first < target) {
                // go right
                left = mid + 1;
                continue;
            }

            if (pairs[mid].first > target) {
                // go left
                right = mid - 1;
                continue;
            }
        }

        mid = (left + right) / 2;

        if (pairs[mid].first == target) {
            return pairs[(left + right) / 2].second;
        } 

        if (mid != 0) {
            return pairs[mid - 1].second;
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
