class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> heap;
        for(int x : gifts)
            heap.push(x);
        while(k--) {
            int x = heap.top();
            heap.pop();
            heap.push(sqrt(x));
        }
        long long ans = 0;
        while(!heap.empty()) {
            int x = heap.top();
            heap.pop();
            ans += x;
        }
        return ans;
    }
};
