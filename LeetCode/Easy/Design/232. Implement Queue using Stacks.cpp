class MyQueue {
private:
    stack<int> inStack;   // For enqueue operation
    stack<int> outStack;  // For dequeue operation

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if (outStack.empty()) {
            // Transfer elements from inStack to outStack
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        int frontElement = outStack.top();
        outStack.pop();
        return frontElement;
    }
    
    int peek() {
        if (outStack.empty()) {
            // Transfer elements from inStack to outStack
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
