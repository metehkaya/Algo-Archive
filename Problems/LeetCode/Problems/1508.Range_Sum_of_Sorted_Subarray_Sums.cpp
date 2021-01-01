class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int rangeSum(vector<int>& ar, int n, int left, int right) {
        vector<int> v;
        vector<int> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + ar[i-1];
        for( int i = 1 ; i <= n ; i++ )
            for( int j = i ; j <= n ; j++ )
                v.push_back(sum[j]-sum[i-1]);
        sort(v.begin(),v.end());
        int ans = 0;
        for( int i = left-1 ; i <= right-1 ; i++ )
            ans = (ans + v[i]) % MOD;
        return ans;
    }
};