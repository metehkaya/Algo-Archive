class Solution {
public:
    int cnt[46];
    int countBalls(int l, int r) {
        int ans = 0;
        memset(cnt,0,sizeof(cnt));
        for( int i = l ; i <= r ; i++ ) {
            int x = i;
            int sum = 0;
            while(x) {
                sum += x%10;
                x /= 10;
            }
            ans = max(ans,++cnt[sum]);
        }
        return ans;
    }
};