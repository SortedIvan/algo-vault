class RecentCounter {
private:
    int recentCounter = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> callQueue;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int range = t - 3000;
        int result = recentCounter;
        while (!callQueue.empty()) {
            int top = callQueue.top();

            if (top >= range) {
                break;
            }

            recentCounter--;
            result--;
            callQueue.pop();
        }
        callQueue.push(t);
        recentCounter++;
        return result + 1;
    }
};

/**
 * Your RecentCounter object will be instantiated and call  d as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
