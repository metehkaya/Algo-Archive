typedef long long LL;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for( int cnt = 1 ; cnt <= 60 ; cnt++ ) {
            LL num = num1 - (LL)cnt*num2;
            if(num < cnt)
                return -1;
            int bmask_cnt = 0;
            for( int i = 0 ; i <= 60 ; i++ )
                if(num & (1LL<<i))
                    bmask_cnt++;
            if(bmask_cnt <= cnt)
                return cnt;
        }
        return -1;
    }
};
