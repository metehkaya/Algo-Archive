typedef long long LL;

class Solution {
public:
    int chalkReplacer(vector<int>& ar, int K) {
        LL sum = 0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        LL k = K;
        k %= sum;
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] > k)
                return i;
            k -= ar[i];
        }
        return -1;
    }
};