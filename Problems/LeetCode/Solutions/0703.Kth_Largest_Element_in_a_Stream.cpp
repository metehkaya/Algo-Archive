class KthLargest {
public:
    int k,cnt;
    priority_queue<int,vector<int>,greater<int>> heap;
    KthLargest(int k, vector<int>& ar) {
        cnt = 0;
        this->k = k;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            add(ar[i]);
    }
    int add(int val) {
        int res = INT_MIN;
        if(cnt < k) {
            heap.push(val);
            if(++cnt == k)
                res = heap.top();
        }
        else {
            if(val >= heap.top()) {
                heap.pop();
                heap.push(val);
            }
            res = heap.top();
        }
        return res;
    }
};