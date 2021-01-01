class Solution {
public:
    int furthestBuilding(vector<int>& ar, int x, int y) {
        int n = ar.size();
        priority_queue<int,vector<int>,greater<int>> heap;
        for( int i = 0 ; i < n-1 ; i++ )
            if(ar[i+1] > ar[i]) {
                int diff = ar[i+1]-ar[i];
                if(y) {
                    y--;
                    heap.push(diff);
                }
                else {
                    if(!heap.empty() && heap.top() > diff)
                        x -= diff;
                    else if(!heap.empty()) {
                        int tp = heap.top();
                        heap.pop();
                        heap.push(diff);
                        x -= tp;
                    }
                    else {
                        x -= diff;
                    }
                    if(x < 0)
                        return i;
                }
            }
        return n-1;
    }
};