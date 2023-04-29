class Solution {
public:
    const int MOD = (int) 1e9+7;
    int numSubseq(vector<int>& ar, int mx) {
        int n = ar.size();
        int ans = 0;
        vector<int> pw(n,1);
        for( int i = 1 ; i < n ; i++ )
            pw[i] = 2*pw[i-1] % MOD;
        sort(ar.begin(),ar.end());
        for( int i = 0 , j = n-1 ; i < n && 2*ar[i] <= mx ; i++ ) {
            while(ar[i]+ar[j] > mx)
                j--;
            int k = j-i;
            ans = (ans + pw[k]) % MOD;
        }
        return ans;
    }
};