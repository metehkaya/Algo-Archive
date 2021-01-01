typedef pair<int,int> pi;

class Solution {
public:
    int maxResult(vector<int>& ar, int k) {
        int n = ar.size();
        int ans = ar[0];
        priority_queue<pi> heap;
        heap.push(pi(ar[0],0));
        for( int i = 1 ; i < n ; i++ ) {
            while(i - heap.top().second > k)
                heap.pop();
            ans = heap.top().first + ar[i];
            heap.push(pi(ans,i));
        }
        return ans;
    }
};