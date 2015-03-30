// 155 Min Stack
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// 
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

class MinStack {
public:
    void push(int x) {
        if (data.empty()){
            data.emplace_back(x, x);
        }
        else
        {
            int curMin = min(data.back().second, x);
            data.emplace_back(x, curMin);
        }
    }

    void pop() {
        data.pop_back();
    }

    int top() {
        return data.back().first;
    }

    int getMin() {
        return data.back().second;
    }

    vector<pair<int, int>> data;
};