bool solution(int n, vector<vector<int>> roads) {
    vector<vector<int>> adj(n);
    for(auto& e : roads) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<vector<bool>> mark(n,vector<bool>(n,false));
    for( int u = 0 ; u < n ; u++ ) {
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            mark[u][adj[u][i]] = mark[adj[u][i]][u] = true;
        for( int i = 0 ; i < deg ; i++ )
            for( int j = i+1 ; j < deg ; j++ )
                mark[adj[u][i]][adj[u][j]] = mark[adj[u][j]][adj[u][i]] = true;
    }
    for( int i = 0 ; i < n ; i++ )
        for( int j = i+1 ; j < n ; j++ )
            if(!mark[i][j])
                return false;
    return true;
}
