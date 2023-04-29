class Solution {
public:
    string shortestSuperstring(vector<string>& ar) {
        int n = ar.size() , total = 0;
        for( int i = 0 ; i < n ; i++ )
            total += ar[i].length();
        int ov[n][n];
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                string a = ar[i];
                string b = ar[j];
                int lena = a.length();
                int lenb = b.length();
                for( int k = min(lena,lenb) ; k >= 0 ; k-- ) {
                    bool ok = true;
                    for( int l = 0 ; l < k ; l++ )
                        if(a[lena-k+l] != b[l])
                            ok = false;
                    if(ok) {
                        ov[i][j] = k;
                        break;
                    }
                }
            }
        int N = (1<<n);
        int dp[N][n];
        int best[N][n];
        memset(dp,0,sizeof(dp));
        memset(best,-1,sizeof(best));
        for( int bm = 1 ; bm < N-1 ; bm++ ) {
            vector<int> v1,v2;
            for( int i = 0 ; i < n ; i++ )
                if(bm & (1<<i))
                    v1.push_back(i);
                else
                    v2.push_back(i);
            for( int i = 0 ; i < v1.size() ; i++ )
                for( int j = 0 ; j < v2.size() ; j++ )
                    if(dp[bm][v1[i]] + ov[v1[i]][v2[j]] >= dp[bm|(1<<v2[j])][v2[j]]) {
                        dp[bm|(1<<v2[j])][v2[j]] = dp[bm][v1[i]] + ov[v1[i]][v2[j]];
                        best[bm|(1<<v2[j])][v2[j]] = v1[i];
                    }
        }
        int last = 0;
        for( int i = 1 ; i < n ; i++ )
            if(dp[N-1][i] > dp[N-1][last])
                last = i;
        vector<int> v;
        int bm = N-1;
        v.push_back(last);
        while(best[bm][last] != -1) {
            int bef = best[bm][last];
            bm -= (1<<last);
            last = bef;
            v.push_back(last);
        }
        reverse(v.begin(),v.end());
        string ans = ar[v[0]];
        for( int i = 1 ; i < n ; i++ )
            ans += ar[v[i]].substr(ov[v[i-1]][v[i]]);
        return ans;
    }
};