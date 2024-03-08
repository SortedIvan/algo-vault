class MinStack {
public:

    int stackPointer = -1;
    int minStackPointer = -1;
    int stack[30005] = {0};
    int minStack[30005] = {0};

    MinStack() {
        
    }
    
    void push(int val) {
        if (stackPointer == -1) {
            minStackPointer++;
            stackPointer++;

            stack[stackPointer] = val;
            minStack[minStackPointer] = val;

            return;
        }

        if (minStack[minStackPointer] >= val) {
            minStack[minStackPointer + 1] = val;
            minStackPointer++;
        }

        stack[stackPointer + 1] = val;
        stackPointer++;
    }
    
    void pop() {

        if (stackPointer == -1) {
            return;
        }

        if (minStack[minStackPointer] == stack[stackPointer]) {
            minStack[minStackPointer] = 0;
            minStackPointer--;
        }

        stack[stackPointer] = 0;
        stackPointer--;
    }
    
    int top() {
        return stack[stackPointer];    
    }
    
    int getMin() {
        return minStack[minStackPointer];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
