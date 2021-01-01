class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> Q;
        vector<int> ans;
        int n = arr.size();
        for( int i = 0 ; i < n ; i++ ) {
            while(!Q.empty() && arr[i] > arr[Q.back()])
                Q.pop_back();
            while(!Q.empty() && Q.front() <= i-k)
                Q.pop_front();
            Q.push_back(i);
            if(i >= k-1)
                ans.push_back(arr[Q.front()]);
        }
        return ans;
    }
};