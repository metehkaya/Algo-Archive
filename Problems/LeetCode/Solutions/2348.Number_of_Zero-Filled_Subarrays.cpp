typedef long long LL;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& ar) {
        int n = ar.size();
        LL ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            if(ar[i] == 0) {
                LL k = j-i;
                ans += k*(k+1)/2;
            }
        }
        return ans;
    }
};
