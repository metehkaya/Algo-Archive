class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({nums2[i],nums1[i]});
        sort(v.begin() , v.end() , [&](vector<int>& a , vector<int>& b) {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        long long total = 0;
        priority_queue<int,vector<int>,greater<int>> heap;
        for( int i = n-k+1 ; i < n ; i++ ) {
            heap.push(v[i][1]);
            total += v[i][1];
        }
        long long ans = 0;
        for( int i = n-k ; i >= 0 ; i-- ) {
            ans = max(ans,(total+v[i][1])*v[i][0]);
            if(!heap.empty() and v[i][1] > heap.top()) {
                total -= heap.top();
                total += v[i][1];
                heap.pop();
                heap.push(v[i][1]);
            }
        }
        return ans;
    }
};
