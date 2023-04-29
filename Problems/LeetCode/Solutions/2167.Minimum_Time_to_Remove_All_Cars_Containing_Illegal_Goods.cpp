class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        vector<int> dpl(n+1);
        vector<int> dpr(n+1);
        dpl[0] = 0;
        for( int i = 0 ; i < n ; i++ )
            dpl[i+1] = min(i+1,dpl[i]+2*(s[i]-'0'));
        dpr[n] = 0;
        for( int i = n-1 ; i >= 0 ; i-- )
            dpr[i] = min(n-i,dpr[i+1]+2*(s[i]-'0'));
        int ans = n;
        for( int i = 0 ; i <= n ; i++ )
            ans = min(ans,dpl[i]+dpr[i]);
        return ans;
    }
};
