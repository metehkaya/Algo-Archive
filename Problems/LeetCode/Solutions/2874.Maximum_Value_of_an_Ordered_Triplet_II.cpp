class Solution {
public:
    long long maximumTripletValue(vector<int>& v) {
        long long ans = 0;
        int n = v.size();
        int mn = min(v[0],v[1]);
        int mx = max(v[0],v[1]);
        int best_diff = max(v[0]-v[1],0);
        for( int i = 2 ; i < n ; i++ ) {
            ans = max(ans,(long long)v[i]*best_diff);
            best_diff = max(best_diff,mx-v[i]);
            mx = max(mx,v[i]);
        }
        return ans;
    }
};
