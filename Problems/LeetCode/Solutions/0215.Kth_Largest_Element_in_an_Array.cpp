class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int,vector<int>,greater<int>> heap;
        for( int i = 0 ; i < k ; i++ )
            heap.push(arr[i]);
        for( int i = k ; i < n ; i++ )
            if( arr[i] > heap.top() ) {
                heap.pop();
                heap.push(arr[i]);
            }
        return heap.top();
    }
};