class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& edges, vector<string>& names, vector<string>& target) {
        vector<int> adj[n];
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int m = target.size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        vector<vector<int>> bef(m,vector<int>(n,-1));
        for( int i = 0 ; i < n ; i++ )
            dp[0][i] = (names[i] != target[0]);
        for( int k = 1 ; k < m ; k++ )
            for( int i = 0 ; i < n ; i++ ) {
                int add = (names[i] != target[k]);
                for(int v : adj[i]) {
                    int cost = dp[k-1][v]+add;
                    if(cost < dp[k][i]) {
                        dp[k][i] = cost;
                        bef[k][i] = v;
                    }
                }
            }
        int idx = 0 , curr = m-1;
        for( int i = 1 ; i < n ; i++ )
            if(dp[m-1][i] < dp[m-1][idx])
                idx = i;
        vector<int> ans({idx});
        while(curr > 0) {
            idx = bef[curr][idx];
            ans.push_back(idx);
            curr--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
