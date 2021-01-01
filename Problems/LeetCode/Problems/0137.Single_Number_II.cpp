class Solution {
public:
    int singleNumber(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int k = 0 ; k < 32 ; k++ ) {
            int cnt = 0;
            for( int i = 0 ; i < n ; i++ )
                if( ar[i] & (1<<k) )
                    cnt++;
            cnt %= 3;
            ans |= (cnt << k);
        }
        return ans;
    }
};