class Solution {
public:
    long long maxKelements(vector<int>& v, int k) {
        long long ans = 0;
        priority_queue<int> heap;
        for(int x : v)
            heap.push(x);
        while(k && !heap.empty()) {
            k--;
            int x = heap.top();
            heap.pop();
            ans += x;
            x = (x+2)/3;
            if(x)
                heap.push(x);
        }
        return ans;
    }
};
