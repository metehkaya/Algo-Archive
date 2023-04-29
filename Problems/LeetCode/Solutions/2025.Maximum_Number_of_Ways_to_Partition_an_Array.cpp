typedef long long LL;

class Solution {
public:
    static const int maxn = 100003;
    int n,ans;
    LL sum[maxn];
    int left[maxn];
    int right[maxn];
    map<LL,int> mp;
    int waysToPartition(vector<int>& ar, int k) {
        n = ar.size();
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        for( int i = 1 ; i < n ; i++ )
            if(sum[i] == sum[n]-sum[i])
                ans++;
        for( int i = 2 ; i <= n ; i++ ) {
            int val = ar[i-1];
            mp[2*sum[i-1]]++;
            right[i] = mp[sum[n]+k-val];
        }
        mp.clear();
        for( int i = n-1 ; i >= 1 ; i-- ) {
            int val = ar[i-1];
            mp[2*sum[i]]++;
            left[i] = mp[sum[n]+val-k];
        }
        for( int i = 1 ; i <= n ; i++ )
            ans = max(ans,left[i]+right[i]);
        return ans;
    }
};