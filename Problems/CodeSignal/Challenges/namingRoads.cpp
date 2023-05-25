bool solution(vector<vector<int>> roads) {
    int m = roads.size();
    vector<vector<int>> vertices(m);
    for(auto& edge : roads)
        vertices[edge[2]] = {edge[0],edge[1]};
    for( int i = 1 ; i < m ; i++ )
        for( int j = 0 ; j < 2 ; j++ )
            for( int k = 0 ; k < 2 ; k++ )
                if(vertices[i][j] == vertices[i-1][k])
                    return false;
    return true;
}
