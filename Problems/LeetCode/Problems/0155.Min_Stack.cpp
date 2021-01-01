class MinStack {
public:
    stack<int> mins;
    stack<int> nums;
    MinStack() {}
    void push(int x) {
        if(nums.empty()) {
            nums.push(x);
            mins.push(x);
        }
        else {
            int minValue = min( mins.top() , x );
            nums.push(x);
            mins.push(minValue);
        }
    }
    void pop() {
        if(!nums.empty()) {
            nums.pop();
            mins.pop();
        }
    }
    int top() {
        return nums.top();
    }
    int getMin() {
        return mins.top();
    }
};