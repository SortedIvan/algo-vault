class CustomStack {
private:
vector<int> stack;
int maxSize = 0;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;        
    }
    
    void push(int x) {
        
        if (stack.size() == maxSize) {
            return;
        }
        
        stack.push_back(x);
    }
    
    int pop() {
        
        if (stack.size() == 0) {
            return -1;
        }


        int nr = stack[stack.size() - 1];
        stack.pop_back();
        return nr;
    }
    
    void increment(int k, int val) {
        
        if (k > stack.size()) {
            k = stack.size();
        }


        for (int i = 0; i < k; ++i) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
