class Solution {
public:
    int getXORSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> cnta(30,0);
        vector<int> cntb(30,0);
        for( int i = 0 ; i < n ; i++ )
            for( int k = 0 ; k < 30 ; k++ )
                if(a[i] & (1<<k))
                    cnta[k]++;
        for( int i = 0 ; i < m ; i++ )
            for( int k = 0 ; k < 30 ; k++ )
                if(b[i] & (1<<k))
                    cntb[k]++;
        int ans = 0;
        for( int i = 0 ; i < 30 ; i++ )
            if(cnta[i] % 2 && cntb[i] % 2)
                ans |= (1<<i);
        return ans;
    }
};