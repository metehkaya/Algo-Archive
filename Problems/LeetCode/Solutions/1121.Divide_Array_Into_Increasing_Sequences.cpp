class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& ar, int limit) {
        int n = ar.size();
        int sz = 0;
        priority_queue<int,vector<int>,greater<int>> heap;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            int diff = j-i;
            sz = max(sz,diff);
        }
        for( int i = 0 ; i < sz ; i++ )
            heap.push(0);
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            int diff = j-i;
            vector<int> v;
            for( int k = 0 ; k < diff ; k++ ) {
                v.push_back(heap.top());
                heap.pop();
            }
            for( int k = 0 ; k < diff ; k++ )
                heap.push(v[k]+1);
        }
        return heap.top() >= limit;
    }
};