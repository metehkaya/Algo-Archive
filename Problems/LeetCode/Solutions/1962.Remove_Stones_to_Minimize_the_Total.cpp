class Solution {
public:
    int minStoneSum(vector<int>& ar, int k) {
        int n = ar.size();
        priority_queue<int> heap;
        for( int i = 0 ; i < n ; i++ )
            heap.push(ar[i]);
        while(k--) {
            int val = heap.top();
            heap.pop();
            val -= val/2;
            heap.push(val);
        }
        int ans = 0;
        while(n--) {
            int val = heap.top();
            heap.pop();
            ans += val;
        }
        return ans;
    }
};