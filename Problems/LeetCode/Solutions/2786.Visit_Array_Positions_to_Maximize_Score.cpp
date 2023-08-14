class Solution {
public:
    long long maxScore(vector<int>& v, int x) {
        int n = v.size();
        long long ans = v[0];
        vector<long long> best({LLONG_MIN,LLONG_MIN});
        best[v[0]%2] = v[0];
        for( int i = 1 ; i < n ; i++ ) {
            int p = v[i]%2;
            long long res = best[p];
            if(best[!p] != LLONG_MIN)
                res = max(res,best[!p]-x);
            res += v[i];
            ans = max(ans, res);
            best[p] = max(best[p], res);
        }
        return ans;
    }
};
