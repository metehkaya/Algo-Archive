class CustomStack {
public:
    int curr;
    int maxSize;
    stack<int> st;
    unordered_map<int,int> incs;
    CustomStack(int maxSize) {
        curr = 0;
        this->maxSize = maxSize;
    }
    void push(int x) {
        if(curr == maxSize)
            return;
        curr++;
        st.push(x);
    }
    int pop() {
        if(curr == 0)
            return -1;
        auto it = incs.find(curr--);
        int res = st.top();
        st.pop();
        if(it != incs.end()) {
            int add = it->second;
            res += add;
            incs.erase(it);
            if(curr)
                incs[curr] += add;
        }
        return res;
    }
    void increment(int k, int val) {
        if(val == 0)
            return;
        k = min(k,curr);
        incs[k] += val;
    }
};