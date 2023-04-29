class Solution {
public:
    int connectSticks(vector<int>& ar) {
        int n = ar.size();
        priority_queue<int,vector<int>,greater<int>> heap;
        for( int i = 0 ; i < n ; i++ )
            heap.push(ar[i]);
        int ans = 0;
        while(n > 1) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            ans += x+y;
            heap.push(x+y);
            n--;
        }
        return ans;
    }
};