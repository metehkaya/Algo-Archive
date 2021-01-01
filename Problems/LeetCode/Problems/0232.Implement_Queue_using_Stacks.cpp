class MyQueue {
public:
    stack<int>A,B;
    MyQueue() {
    }
    void push(int x) {
        while(!A.empty()) {
            int val = A.top();
            A.pop();
            B.push(val);
        }
        B.push(x);
        while(!B.empty()) {
            int val = B.top();
            B.pop();
            A.push(val);
        }
    }
    int pop() {
        int val = A.top();
        A.pop();
        return val;
    }
    int peek() {
        return A.top();
    }
    bool empty() {
        return A.empty();
    }
};