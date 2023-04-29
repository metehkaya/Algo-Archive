typedef long long LL;

class Solution {
public:
    int N,n;
    LL sum;
    bool mark[(1<<15)];
    vector<int> ar;
    bool f(int bmask , LL x) {
        if(bmask == N)
            return true;
        if(mark[bmask])
            return false;
        mark[bmask] = true;
        for( int i = 0 ; i < n ; i++ )
            if((bmask&(1<<i)) == 0)
                if(x+ar[i] <= sum)
                    if(f((bmask|(1<<i)),(x+ar[i])%sum))
                        return true;
        return false;
    }
    bool makesquare(vector<int>& ar) {
        this->ar = ar;
        n = ar.size();
        N = (1<<n)-1;
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        if(sum % 4)
            return false;
        sum /= 4;
        return f(0,0);
    }
};