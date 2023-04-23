int solution(vector<vector<int>> v) {
    int n = v.size() , m = v[0].size() , ans = 0;
    for( int j = 0 ; j < m ; j++ )
        for( int i = 0 ; i < n ; i++ )
            if(v[i][j] > 0)
                ans += v[i][j];
            else
                break;
    return ans;
}
