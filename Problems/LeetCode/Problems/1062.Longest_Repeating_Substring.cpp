typedef long long LL;

class Solution {
public:
    const LL MOD = 1e9+7;
    bool check(string& str , int n , int k) {
        set<LL> s;
        LL val = 0;
        LL most = 1;
        for( int i = 0 ; i < k ; i++ ) {
            val = (26*val + str[i]-'a') % MOD;
            if(i)
                most = (26*most) % MOD;
        }
        s.insert(val);
        for( int i = k ; i < n ; i++ ) {
            LL dec = (most * (str[i-k]-'a')) % MOD;
            val = (val - dec + MOD) % MOD;
            val = (26*val + str[i]-'a') % MOD;
            if(s.find(val) != s.end())
                return true;
            s.insert(val);
        }
        return false;
    }
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        int l = 1 , r = n-1 , ans = 0;
        while(l <= r) {
            int mid = (l+r)>>1;
            if(check(s,n,mid))
                ans = mid , l = mid+1;
            else
                r = mid-1;
        }
        return ans;
    }
};