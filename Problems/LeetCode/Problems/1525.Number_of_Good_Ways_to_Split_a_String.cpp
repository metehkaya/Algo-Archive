class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        if(n <= 1)
            return 0;
        vector<int> cntp(n);
        vector<int> cnts(n);
        vector<bool> varp(256,false);
        vector<bool> vars(256,false);
        cntp[0] = 1;
        varp[s[0]] = true;
        for( int i = 1 ; i < n ; i++ ) {
            cntp[i] = cntp[i-1] + !varp[s[i]];
            varp[s[i]] = true;
        }
        cnts[n-1] = 1;
        vars[s[n-1]] = true;
        for( int i = n-2 ; i >= 0 ; i-- ) {
            cnts[i] = cnts[i+1] + !vars[s[i]];
            vars[s[i]] = true;
        }
        int ans = 0;
        for( int i = 0 ; i < n-1 ; i++ )
            ans += (cntp[i] == cnts[i+1]);
        return ans;
    }
};