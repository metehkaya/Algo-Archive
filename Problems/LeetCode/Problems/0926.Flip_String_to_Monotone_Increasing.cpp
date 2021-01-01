class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length() , ans = n;
        vector<int> sum(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            sum[i] = sum[i-1] + s[i-1] - '0';
        for( int i = 0 ; i <= n ; i++ ) {
            int l1 = sum[i];
            int l0 = i - l1;
            int r1 = sum[n] - l1;
            int r0 = n - i - r1;
            ans = min( ans , l1+r0 );
        }
        return ans;
    }
};