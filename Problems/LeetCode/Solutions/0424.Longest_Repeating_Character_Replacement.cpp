class Solution {
public:
    int n,ans;
    vector<int> v[26];
    int characterReplacement(string s, int k) {
        n = s.length();
        for( int i = 0 ; i < n ; i++ )
            v[s[i]-'A'].push_back(i);
        for( int c = 0 ; c < 26 ; c++ ) {
            int sz = v[c].size();
            for( int i = 0 ; i < sz ; i++ ) {
                int l = i , r = sz-1 , idx = -1;
                while(l <= r) {
                    int m = (l+r) >> 1;
                    int rem = v[c][m]-v[c][i]+1 - (m-i+1);
                    if(rem <= k)
                        idx = m , l = m+1;
                    else
                        r = m-1;
                }
                int len = min(n,idx-i+1+k);
                ans = max(ans,len);
            }
        }
        return ans;
    }
};