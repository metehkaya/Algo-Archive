int solution(vector<int> v) {
    int n = v.size() , ans = INT_MIN;
    for( int i = 1 ; i < n ; i++ )
        ans = max(ans,v[i]*v[i-1]);
    return ans;
}
