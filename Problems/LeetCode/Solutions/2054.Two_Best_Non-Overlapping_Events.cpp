class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& ar) {
        int n = ar.size() , ans = 0 , mx = 0;
        sort(ar.begin(),ar.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for( int i = 0 ; i < n ; i++ ) {
            while(!pq.empty() && pq.top().first < ar[i][0]) {
                mx = max(mx, pq.top().second);
                pq.pop();
            }
            pq.push(make_pair(ar[i][1],ar[i][2]));
            ans = max(ans,mx+ar[i][2]);
        }
        return ans;
    }
};
