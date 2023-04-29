typedef long long LL;

class Solution {
public:
    LL minimumRemoval(vector<int>& ar) {
        int n = ar.size();
        ar.push_back(0);
        sort(ar.begin(),ar.end());
        vector<LL> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1]+ar[i];
        LL ans = sum[n-1] , cost = 0;
        for( int i = n-1 ; i > 0 ; i-- ) {
            cost += (LL)(n-i)*(ar[i+1]-ar[i]);
            ans = min(ans,cost+sum[i-1]);
        }
        return ans;
    }
};
