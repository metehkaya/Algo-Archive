class Solution {
public:
    int f(int id, int bm, vector<vector<int>>& w, vector<vector<int>>& b, vector<int>& dp) {
        if(id == w.size())
            return dp[bm] = 0;
        if(dp[bm] != -1)
            return dp[bm];
        dp[bm] = INT_MAX;
        for( int i = 0 ; i < (int) b.size() ; i++ )
            if( (bm & (1<<i)) == 0 ) {
                int dist = abs(w[id][0]-b[i][0]) + abs(w[id][1]-b[i][1]);
                dp[bm] = min( dp[bm] , f( id+1 , (bm|(1<<i)) , w , b , dp ) + dist );
            }
        return dp[bm];
    }
    int assignBikes(vector<vector<int>>& w, vector<vector<int>>& b) {
        int n = w.size();
        int m = b.size();
        vector<int> dp(1<<m,-1);
        return f(0,0,w,b,dp);
    }
};