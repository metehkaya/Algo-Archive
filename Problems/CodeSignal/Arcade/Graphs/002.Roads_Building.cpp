vector<vector<int>> solution(int n, vector<vector<int>> G) {
    vector<vector<int>> ans;
    vector<vector<bool>> mark(n,vector<bool>(n,false));
    for(auto& e : G)
        mark[e[0]][e[1]] = mark[e[1]][e[0]] = true;
    for( int i = 0 ; i < n ; i++ )
        for( int j = i+1 ; j < n ; j++ )
            if(!mark[i][j])
                ans.push_back({i,j});
    return ans;
}
