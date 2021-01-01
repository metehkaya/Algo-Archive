class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        int m = ar[0].size();
        if(m == 0)
            return 0;
        int cnt[n][m];
        memset(cnt,0,sizeof(cnt));
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> idx;
            int cnt0 = 0 , cntE = 0;
            for( int j = 0 ; j < m ; j++ ) {
                if(ar[i][j] == '0')
                    cnt0++ , idx.push_back(j);
                else if(ar[i][j] == 'E')
                    cntE++;
                else {
                    for( int k = 0 ; k < cnt0 ; k++ )
                        cnt[i][idx[k]] += cntE;
                    idx.clear();
                    cnt0 = cntE = 0;
                }
            }
            for( int k = 0 ; k < cnt0 ; k++ )
                cnt[i][idx[k]] += cntE;
        }
        for( int j = 0 ; j < m ; j++ ) {
            vector<int> idx;
            int cnt0 = 0 , cntE = 0;
            for( int i = 0 ; i < n ; i++ ) {
                if(ar[i][j] == '0')
                    cnt0++ , idx.push_back(i);
                else if(ar[i][j] == 'E')
                    cntE++;
                else {
                    for( int k = 0 ; k < cnt0 ; k++ )
                        cnt[idx[k]][j] += cntE;
                    idx.clear();
                    cnt0 = cntE = 0;
                }
            }
            for( int k = 0 ; k < cnt0 ; k++ )
                cnt[idx[k]][j] += cntE;
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ans = max(ans,cnt[i][j]);
        return ans;
    }
};