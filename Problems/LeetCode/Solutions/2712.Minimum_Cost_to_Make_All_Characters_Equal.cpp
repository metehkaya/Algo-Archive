class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        vector<long long> l(n,0) , r(n,0);
        for( int i = 1 ; i < n ; i++ )
            l[i] = (s[i] == s[i-1]) ? l[i-1] : l[i-1]+i;
        for( int i = n-2 ; i >= 0 ; i-- )
            r[i] = (s[i] == s[i+1]) ? r[i+1] : r[i+1]+(n-1-i);
        long long ans = LLONG_MAX;
        for( int i = 0 ; i < n ; i++ )
            ans = min(ans,l[i]+r[i]);
        return ans;
    }
};
