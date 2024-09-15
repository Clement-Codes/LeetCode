#include<stack>
class MinStack {

public:
    stack<int> s;
    stack<int> ms;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        ms.push(min(val, ms.size()>0?ms.top():val));
    }
    
    void pop() {
        s.pop();
        ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
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