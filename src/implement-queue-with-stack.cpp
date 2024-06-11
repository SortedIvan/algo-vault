class MyQueue {
private:
    // idea: swap elements to keep one stack always in order

    stack<int> first;
    stack<int> second;

public:
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        if (first.empty())
        {
            first.push(x);
        }
        else
        {
            // move all of them into the second stack
            while (!first.empty())
            {
                int top = first.top();
                second.push(top);
                first.pop();
            }

            // push the new element into the first
            first.push(x);

            // return the elements back into the second one
            while(!second.empty())
            {
                int top = second.top();
                first.push(top);
                second.pop();
            }
        }
    }
    
    int pop() 
    {
        int top = first.top();
        first.pop();
        return top;
    }
    
    int peek() 
    {
        return first.top();
    }
    
    bool empty() 
    {
        return first.empty();   
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
