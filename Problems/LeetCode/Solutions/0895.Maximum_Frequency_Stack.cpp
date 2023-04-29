class FreqStack {
public:
    int maxFreq;
    map<int,int> freq;
    map<int,stack<int>> nums;
    FreqStack() {
        maxFreq = 0;
    }
    void push(int x) {
        int f = freq[x]+1;
        freq[x] = f;
        nums[f].push(x);
        maxFreq = max(maxFreq,f);
    }
    int pop() {
        int x = nums[maxFreq].top();
        nums[maxFreq].pop();
        freq[x] = maxFreq-1;
        while(maxFreq > 0 && nums[maxFreq].empty())
            maxFreq--;
        return x;
    }
};