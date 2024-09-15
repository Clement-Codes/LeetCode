import java.util.Stack;

class MinStack {
    Stack<Integer> s = new Stack<Integer>();
    Stack<Integer> ms = new Stack<Integer>();    

    public MinStack() {

    }
    
    public void push(int val) {
        this.s.add(val);
        this.ms.add(Math.min(val, this.ms.size()>0?this.ms.peek():val));
    }
    
    public void pop() {
        this.s.pop();
        this.ms.pop();
    }
    
    public int top() {
        return this.s.peek();
    }
    
    public int getMin() {
        return this.ms.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */