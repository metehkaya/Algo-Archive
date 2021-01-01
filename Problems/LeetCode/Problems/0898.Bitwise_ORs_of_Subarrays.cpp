class Solution {
public:
    int subarrayBitwiseORs(vector<int>& ar) {
        int n = ar.size();
        unordered_set<int> values;
        vector<int> lg2(n+1);
        for( int i = 2 ; i <= n ; i++ )
            lg2[i] = lg2[i/2]+1;
        int k = lg2[n];
        vector<vector<int>> dp(n,vector<int>(k+1));
        for( int i = 0 ; i < n ; i++ )
            dp[i][0] = ar[i];
        for( int j = 1 ; j <= k ; j++ )
            for( int i = 0 ; i+(1<<j) <= n ; i++ )
                dp[i][j] = ( dp[i][j-1] | dp[i+(1<<(j-1))][j-1] );
        for( int i = 0 ; i < n ; i++ ) {
            if(i && ar[i] == ar[i-1])
                continue;
            int last = i , lastVal = ar[i];
            while(last < n) {
                int l = last , r = n-1 , noChange = last , biggerOr = -1;
                while(l <= r) {
                    int mid = (l+r) >> 1;
                    int len = mid-i+1;
                    int j = lg2[len];
                    int val = ( dp[i][j] | dp[mid-(1<<j)+1][j] );
                    if(val == lastVal)
                        noChange = mid , l = mid+1;
                    else
                        biggerOr = val , r = mid-1;
                }
                values.insert(lastVal);
                last = noChange + 1;
                lastVal = biggerOr;
            }
        }
        return values.size();
    }
};