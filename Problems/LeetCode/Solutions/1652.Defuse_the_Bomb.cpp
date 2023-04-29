class Solution {
public:
    vector<int> decrypt(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> sum(2*n+1,0);
        for( int i = 0 ; i < n ; i++ )
            sum[i+1] = sum[i]+ar[i];
        for( int i = 1 ; i <= n ; i++ )
            sum[n+i] = sum[n] + sum[i];
        vector<int> ans;
        for( int i = 1 ; i <= n ; i++ ) {
            if(k == 0)
                ans.push_back(0);
            else if(k > 0)
                ans.push_back(sum[i+k]-sum[i]);
            else
                ans.push_back(sum[n+i-1]-sum[n+i-1+k]);
        }
        return ans;
    }
};