class Solution {
public:
    int minBuildTime(vector<int>& ar, int add) {
        int n = ar.size();
        priority_queue<int,vector<int>,greater<int>> heap;
        for( int i = 0 ; i < n ; i++ )
            heap.push(ar[i]);
        while(n >= 2) {
            n--;
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            heap.push(y+add);
        }
        return heap.top();
    }
};