class Solution {
public:
    int longestMountain(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 1 , inc = 0 , dec = 0 , prv = 0 ; i < n ; i++ ) {
            if(ar[i] > ar[i-1]) {
                inc++;
                prv = dec = 0;
            }
            else if(ar[i] == ar[i-1])
                prv = inc = dec = 0;
            else {
                if(inc) {
                    prv = inc;
                    inc = 0;
                }
                dec++;
                if(prv)
                    ans = max(ans,prv+dec+1);
            }
        }
        return ans;
    }
};