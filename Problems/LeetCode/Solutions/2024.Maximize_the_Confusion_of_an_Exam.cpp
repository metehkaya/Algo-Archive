class Solution {
public:
    int n;
    int sum[50001][2];
    int maxConsecutiveAnswers(string s, int k) {
        n = s.length();
        for( int i = 1 ; i <= n ; i++ ) {
            int c = (s[i-1] == 'T');
            sum[i][0] = sum[i-1][0] + (c == 0);
            sum[i][1] = sum[i-1][1] + (c == 1);
        }
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 0 ; j < 2 ; j++ ) {
                int l = i , r = n , last = i-1;
                while(l <= r) {
                    int m = (l+r) >> 1;
                    int cnt = sum[m][j] - sum[i-1][j];
                    if(cnt <= k)
                        l = m+1 , last = m;
                    else
                        r = m-1;
                }
                ans = max(ans,last-i+1);
            }
        return ans;
    }
};