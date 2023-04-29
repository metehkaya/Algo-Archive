#define mod 1000000007LL
typedef long long LL;

class Solution {
public:
    int numberOfWays(string s) {
        int n = s.length();
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == 'S')
                v.push_back(i);
        int k = v.size();
        if(k % 2 || k == 0)
            return 0;
        LL ans = 1;
        for( int i = 2 ; i < k ; i += 2 )
            ans = (ans * (v[i] - v[i-1])) % mod;
        return ans;
    }
};
