// 716. Max Stack
// Design a max stack that supports push, pop, top, peekMax and popMax.

// push(x) -- Push element x onto stack.
// pop() -- Remove the element on top of the stack and return it.
// top() -- Get the element on the top.
// peekMax() -- Retrieve the maximum element in the stack.
// popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
// Example 1:
// MaxStack stack = new MaxStack();
// stack.push(5); 
// stack.push(1);
// stack.push(5);
// stack.top(); -> 5
// stack.popMax(); -> 5
// stack.top(); -> 1
// stack.peekMax(); -> 5
// stack.pop(); -> 1
// stack.top(); -> 5
// Note:
// -1e7 <= x <= 1e7
// Number of operations won't exceed 10000.
// The last four operations won't be called when stack is empty.

class MaxStack {
    list<int> s;
    map<int, vector<list<int>::iterator>> m;
public:
    /** initialize your data structure here. */
    MaxStack() {   
    }
    
    void push(int x) {
        s.push_back(x);
        m[x].push_back(prev(s.end()));
    }
    
    int pop() {
        int x = s.back();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        s.pop_back();
        return x;
    }
    
    int top() {
        return s.back();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int x = m.rbegin()->first;
        s.erase(m[x].back());
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        return x;
    }
};

// using two stacks
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {  
        addMax(x);
        stk.push(x);
    }
    
    int pop() {
        int val = stk.top();
        if (stk.top() == maxStk.top()) {
            maxStk.pop();
        }
        stk.pop();
        return val;
    }
    
    int top() {
        return stk.top();
    }
    
    int peekMax() {
        return maxStk.top();
    }
    
    int popMax() {
        int val = maxStk.top();
        stack<int> tmp;
        
        while (maxStk.top() != stk.top()) {
            tmp.push(stk.top());
            stk.pop();
        } // maxStk.top() == stk.top()
        
        maxStk.pop();
        stk.pop();
        
        while (!tmp.empty()) {
            stk.push(tmp.top());
            addMax(tmp.top());
            tmp.pop();
        }
        
        return val;
    }
    
private:
    void addMax(int x) {
        if (maxStk.empty() || x >= maxStk.top()) {
            maxStk.push(x);
        }
    }
    
    stack<int> maxStk;
    stack<int> stk;
};
/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */