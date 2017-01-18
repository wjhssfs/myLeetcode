// 155 Min Stack
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
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

The idea is to store the gap between the min value and the current value;
public class MinStack {
    long min;
    Stack<Long> stack;

    public MinStack(){
        stack=new Stack<>();
    }

    public void push(int x) {
        if (stack.isEmpty()){
            stack.push(0L);
            min=x;
        }else{
            stack.push(x-min);//Could be negative if min value needs to change
            if (x<min) min=x;
        }
    }

    public void pop() {
        if (stack.isEmpty()) return;

        long pop=stack.pop();

        if (pop<0)  min=min-pop;//If negative, increase the min value

    }

    public int top() {
        long top=stack.peek();
        if (top>0){
            return (int)(top+min);
        }else{
           return (int)(min);
        }
    }

    public int getMin() {
        return (int)min;
    }
}