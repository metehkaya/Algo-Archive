class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0)
            return 0;
        int n = s.length() , ans = n;
        vector<vector<int>> sum(n+1,{0,0,0});
        for( int i = 1 ; i <= n ; i++ ) {
            sum[i] = sum[i-1];
            int c = s[i-1]-'a';
            sum[i][c]++;
        }
        if(sum[n][0] < k or sum[n][1] < k or sum[n][2] < k)
            return -1;
        for( int idx = 0 ; idx <= n ; idx++ ) {
            int l = idx+1 , r = n , len = n;
            while(l <= r) {
                int m = (l+r) >> 1;
                bool fail = false;
                for( int i = 0 ; i < 3 ; i++ )
                    if(sum[idx][i] + sum[n][i] - sum[m][i] < k)
                        fail = true;
                if(fail)
                    r = m-1;
                else
                    l = m+1 , len = idx+n-m;
            }
            ans = min(ans,len);
        }
        return ans;
    }
};
