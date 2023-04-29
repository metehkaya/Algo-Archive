typedef long long LL;

class Solution {
public:
    vector<int> getAverages(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> ans(n,-1);
        int K = 2*k+1;
        if(K <= n) {
            LL sum = 0;
            for( int i = 0 ; i < K ; i++ )
                sum += ar[i];
            ans[k] = sum/K;
            for( int i = k+1 ; i+k < n ; i++ ) {
                sum -= ar[i-k-1];
                sum += ar[i+k];
                ans[i] = sum/K;
            }
        }
        return ans;
    }
};
