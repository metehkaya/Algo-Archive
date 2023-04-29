typedef long long LL;
#define mod 1000000007LL

class Solution {
public:
    int maxSumRangeQuery(vector<int>& ar, vector<vector<int>>& reqs) {
        int n = ar.size();
        int m = reqs.size();
        vector<int> cnt(n,0);
        for( int i = 0 ; i < m ; i++ ) {
            cnt[reqs[i][0]]++;
            if(reqs[i][1] != n-1)
                cnt[reqs[i][1]+1]--;
        }
        for( int i = 1 ; i < n ; i++ )
            cnt[i] += cnt[i-1];
        sort(ar.begin(),ar.end());
        sort(cnt.begin(),cnt.end());
        LL ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans += (LL) ar[i] * cnt[i];
        return ans%mod;
    }
};