class Solution {
public:
    int lastStoneWeight(vector<int>& ar) {
        int n = ar.size();
        priority_queue<int> heap;
        for( int i = 0 ; i < n ; i++ )
            heap.push(ar[i]);
        int ans = -1;
        while(true) {
            if(heap.empty()) {
                ans = 0;
                break;
            }
            int y = heap.top();
            heap.pop();
            if(heap.empty()) {
                ans = y;
                break;
            }
            else {
                int x = heap.top();
                heap.pop();
                if(x < y)
                    heap.push(y-x);
            }
        }
        return ans;
    }
};