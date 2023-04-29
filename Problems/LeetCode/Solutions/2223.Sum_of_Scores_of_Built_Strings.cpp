class Solution {
public:
    int n;
    void z_func(string& s, vector<int>& z) {
        for( int i = 1 , l = 0 , r = 0 ; i < n ; i++ ) {
            if(i <= r && z[i-l] < r-i+1)
                z[i] = z[i-l];
            else
                for( z[i] = max(0,r-i+1) ; i+z[i] < n && s[z[i]] == s[i+z[i]] ; z[i]++);
            if(i+z[i]-1 > r)
                l = i , r = i+z[i]-1;
        }
    }
    long long sumScores(string s) {
        n = s.length();
        vector<int> z(n,n);
        z_func(s,z);
        long long ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans += z[i];
        return ans;
    }
};
