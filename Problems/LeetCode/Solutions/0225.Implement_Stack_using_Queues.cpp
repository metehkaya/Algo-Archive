class MyStack {
public:
    int n;
    queue<int> q1,q2;
    MyStack() {
        n = 0;
    }
    void push(int x) {
        n++;
        q2.push(x);
        while(!q1.empty()) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        swap(q1,q2);
    }
    int pop() {
        n--;
        int res = q1.front();
        q1.pop();
        return res;
    }
    int top() {
        int res = q1.front();
        return res;
    }
    bool empty() {
        return n == 0;
    }
};