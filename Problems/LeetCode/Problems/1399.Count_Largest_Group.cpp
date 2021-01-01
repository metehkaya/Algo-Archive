class Solution {
public:
    int sumDig(int x) {
        int sum = 0;
        while(x) {
            sum += x%10;
            x /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int> cnt(37,0);
        for( int i = 1 ; i <= n ; i++ )
            cnt[sumDig(i)]++;
        int mx = 0 , mxCnt = 0;
        for( int i = 1 ; i < 37 ; i++ ) {
            if(cnt[i] > mx) {
                mx = cnt[i];
                mxCnt = 1;
            }
            else if(cnt[i] == mx)
                mxCnt++;
        }
        return mxCnt;
    }
};