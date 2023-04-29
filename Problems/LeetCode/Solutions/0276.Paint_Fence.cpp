class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)
            return 0;
        if(n == 1)
            return k;
        if(n == 2)
            return k*k;
        if(k == 0)
            return 0;
        vector<int> ans(n+1);
        ans[0] = 1;
        ans[1] = k;
        ans[2] = k*k;
        for( int i = 3 ; i <= n ; i++ )
            ans[i] = (k-1) * (ans[i-2] + ans[i-1]);
        return ans[n];
    }
};