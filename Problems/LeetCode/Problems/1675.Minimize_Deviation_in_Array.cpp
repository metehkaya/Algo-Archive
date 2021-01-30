class Solution {
public:
    int minimumDeviation(vector<int>& ar) {
        int n = ar.size();
        int minval = INT_MAX;
        priority_queue<int> heap;
        for( int i = 0 ; i < n ; i++ ) {
            int x = ar[i];
            if(x%2)
                x *= 2;
            heap.push(x);
            minval = min(minval,x);
        }
        int res = INT_MAX;
        while(heap.top() % 2 == 0) {
            int x = heap.top();
            heap.pop();
            res = min(res,x-minval);
            x /= 2;
            heap.push(x);
            minval = min(minval,x);
        }
        res = min(res,heap.top()-minval);
        return res;
    }
};