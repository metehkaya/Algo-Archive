class Solution {
public:
    int N,m,bmask,cnt;
    int maxDist,maxV;
    bool mark[15];
    vector<int> adj[15];
    void dfs(int u , int d) {
        cnt++;
        mark[u] = true;
        if(d > maxDist)
            maxDist = d , maxV = u;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if((bmask & (1<<v)) == 0)
                continue;
            if(mark[v])
                continue;
            dfs(v,d+1);
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        N = (1<<n);
        m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n-1,0);
        for( bmask = 1 ; bmask < N ; bmask++ ) {
            int u = 0;
            while(u < n && (bmask & (1<<u)) == 0)
                u++;
            int ncnt = 0;
            for( int i = 0 ; i < n ; i++ )
                if((bmask & (1<<i)) > 0)
                    ncnt++;
            if(ncnt == 1)
                continue;
            cnt = 0;
            maxDist = maxV = -1;
            memset(mark,false,sizeof(mark));
            dfs(u,0);
            if(cnt != ncnt)
                continue;
            u = maxV;
            cnt = 0;
            maxDist = maxV = -1;
            memset(mark,false,sizeof(mark));
            dfs(u,0);
            ans[maxDist-1]++;
        }
        return ans;
    }
};