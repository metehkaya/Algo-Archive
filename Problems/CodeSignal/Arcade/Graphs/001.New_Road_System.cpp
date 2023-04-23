bool solution(vector<vector<bool>> G) {
    int n = G.size();
    vector<int> diffs(n,0);
    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < n ; j++ )
            if(G[i][j])
                diffs[i]++ , diffs[j]--;
    for(int diff : diffs)
        if(diff)
            return false;
    return true;
}
