class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> a(n+2,0) , b(n+2,0);
        for( int i = 1 ; i <= n ; i++ )
            b[i] = b[i-1] + (s[i-1] == 'b');
        for( int i = n ; i >= 1 ; i-- )
            a[i] = a[i+1] + (s[i-1] == 'a');
        int ans = INT_MAX;
        for( int i = 1 ; i <= n ; i++ )
            ans = min( ans , b[i-1] + a[i+1] );
        return ans;
    }
};