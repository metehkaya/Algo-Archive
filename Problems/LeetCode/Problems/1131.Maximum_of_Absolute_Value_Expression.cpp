class Solution {
public:
    int f(int& n, vector<int>& a, vector<int>& b, int sign1, int sign2) {
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back(i+sign1*a[i]+sign2*b[i]);
        int res = 0;
        int minVal = v[0];
        for( int i = 1 ; i < n ; i++ ) {
            minVal = min(minVal, v[i]);
            res = max(res, v[i]-minVal);
        }
        return res;
    }
    int maxAbsValExpr(vector<int>& a, vector<int>& b) {
        int ans = 0;
        int n = a.size();
        if(n == 0)
            return 0;
        ans = max( ans , f(n,a,b,+1,+1) );
        ans = max( ans , f(n,a,b,+1,-1) );
        ans = max( ans , f(n,a,b,-1,+1) );
        ans = max( ans , f(n,a,b,-1,-1) );
        return ans;
    }
};