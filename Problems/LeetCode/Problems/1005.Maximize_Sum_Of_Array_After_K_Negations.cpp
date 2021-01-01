class Solution {
public:
    int largestSumAfterKNegations(vector<int>& ar, int k) {
        int n = ar.size();
        priority_queue<int,vector<int>,greater<int>> heap;
        for( int i = 0 ; i < n ; i++ )
            heap.push(ar[i]);
        for( int i = 0 ; i < k ; i++ ) {
            int num = heap.top();
            heap.pop();
            heap.push(-num);
        }
        int ans = 0;
        while(!heap.empty()) {
            ans += heap.top();
            heap.pop();
        }
        return ans;
    }
};