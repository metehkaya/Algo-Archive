class Solution {
public:
    int maxSatisfied(vector<int>& ar, vector<int>& mark, int k) {
        int n = ar.size();
        vector<int> sum1(n+1,0);
        vector<int> sum2(n+1,0);
        for( int i = 1 ; i <= n ; i++ ) {
            sum1[i] = sum1[i-1] + ar[i-1];
            sum2[i] = sum2[i-1] + ar[i-1]*!mark[i-1];
        }
        int ans = 0;
        for( int i = 1 ; i <= n-k+1 ; i++ ) {
            int res = sum2[i-1] + sum2[n] - sum2[i+k-1];
            res += sum1[i+k-1] - sum1[i-1];
            ans = max(ans,res);
        }
        return ans;
    }
};