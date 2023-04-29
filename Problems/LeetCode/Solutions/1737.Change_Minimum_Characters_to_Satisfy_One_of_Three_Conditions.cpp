class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> na(26,0);
        vector<int> nb(26,0);
        int ans = INT_MAX;
        int n = a.length();
        int m = b.length();
        for( int i = 0 ; i < n ; i++ )
            na[a[i]-'a']++;
        for( int i = 0 ; i < m ; i++ )
            nb[b[i]-'a']++;
        for( int i = 0 ; i < 25 ; i++ ) {
            int cnta = 0;
            int cntb = 0;
            for( int j = 0 ; j <= i ; j++ )
                cnta += na[j];
            for( int j = i+1 ; j < 26 ; j++ )
                cntb += nb[j];
            ans = min(ans,n-cnta+m-cntb);
        }
        for( int i = 0 ; i < 25 ; i++ ) {
            int cnta = 0;
            int cntb = 0;
            for( int j = 0 ; j <= i ; j++ )
                cntb += nb[j];
            for( int j = i+1 ; j < 26 ; j++ )
                cnta += na[j];
            ans = min(ans,n-cnta+m-cntb);
        }
        for( int i = 0 ; i < 26 ; i++ )
            ans = min(ans,n-na[i]+m-nb[i]);
        return ans;
    }
};
