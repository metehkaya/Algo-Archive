class Solution {
public:
    bool check(int n) {
        if(n == 1)
            return false;
        for( int i = 2 ; i*i <= n ; i++ )
            if(n % i == 0)
                return false;
        return true;
    }
    int diagonalPrime(vector<vector<int>>& v) {
        int n = v.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(check(v[i][i]))
                ans = max(ans,v[i][i]);
            if(check(v[n-1-i][i]))
                ans = max(ans,v[n-1-i][i]);
        }
        return ans;
    }
};
