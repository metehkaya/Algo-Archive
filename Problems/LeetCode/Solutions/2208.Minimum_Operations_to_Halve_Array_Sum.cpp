class Solution {
public:
    int halveArray(vector<int>& ar) {
        double sum = 0;
        int n = ar.size();
        priority_queue<double> heap;
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            heap.push(ar[i]);
        }
        int ans = 0;
        double curr = sum;
        while(curr > sum/2) {
            ans++;
            double x = heap.top();
            heap.pop();
            x /= 2;
            curr -= x;
            heap.push(x);
        }
        return ans;
    }
};
