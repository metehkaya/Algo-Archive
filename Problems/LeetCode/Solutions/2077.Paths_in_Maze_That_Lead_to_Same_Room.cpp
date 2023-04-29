class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& edges) {
        bool g[n+1][n+1];
        memset(g,false,sizeof(g));
        for(auto& e : edges) {
            if(e[0] > e[1])
                swap(e[0],e[1]);
            g[e[0]][e[1]] = true;
        }
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = i+1 ; j <= n ; j++ )
                if(g[i][j])
                    for( int k = j+1 ; k <= n ; k++ )
                        if(g[i][k] and g[j][k])
                            ans++;
        return ans;
    }
};
