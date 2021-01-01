class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& reqs, vector<vector<string>>& people) {
        int m = reqs.size();
        int n = people.size();
        map<string,int> reqID;
        for( int i = 0 ; i < reqs.size() ; i++ )
            reqID[reqs[i]] = i;
        int M = (1<<m);
        vector<int> bmask(n);
        vector<vector<int>> dp(n+1,vector<int>(M,INT_MAX));
        vector<vector<int>> best(n+1,vector<int>(M,-1));
        dp[0][0] = 0;
        for( int i = 0 ; i < n ; i++ ) {
            bmask[i] = 0;
            for( int j = 0 ; j < people[i].size() ; j++ )
                bmask[i] |= (1 << reqID[people[i][j]]);
            for( int j = 0 ; j < M ; j++ )
                if(dp[i][j] != INT_MAX) {
                    if(dp[i][j] < dp[i+1][j])
                        dp[i+1][j] = dp[i][j] , best[i+1][j] = j;
                    int j2 = (j | bmask[i]);
                    if(dp[i][j] + 1 < dp[i+1][j2])
                        dp[i+1][j2] = dp[i][j] + 1 , best[i+1][j2] = j;
                }
        }
        vector<int> ans;
        int i = n , j = M-1;
        while(i > 0) {
            int oldj = best[i][j];
            if(oldj != j)
                ans.push_back(i-1);
            i--;
            j = oldj;
        }
        return ans;
    }
};