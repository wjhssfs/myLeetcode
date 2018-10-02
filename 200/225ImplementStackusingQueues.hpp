// 225 Implement Stack using Queues
// Implement the following operations of a stack using queues.
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
// Notes:
// You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

class Stack {
    queue<int> t,q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        transfer();
        t.pop();
    }

    // Get the top element.
    int top() {
        transfer();
        int r = t.front();
        q.push(t.front());t.pop();
        return r;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
    
    void transfer(){
        while(q.size()>1){
            t.push(q.front());q.pop();
        }
        swap(q,t);
    }
};

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i=1; i<q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};