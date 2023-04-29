typedef long long LL;

class Solution {
public:
    bool isPossible(vector<int>& ar) {
        LL sum = 0;
        int n = ar.size();
        priority_queue<int> heap;
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            heap.push(ar[i]);
        }
        while(heap.top() != 1) {
            int val = heap.top();
            LL other = sum - val;
            if(other == 0 || val <= other)
                return false;
            int newVal = (val % other == 0) ? other : val % other;
            sum = other + newVal;
            heap.pop();
            heap.push(newVal);
        }
        return true;
    }
};