bool solution(vector<int> v) {
    int n = v.size();
    bool used = false;
    for( int i = 1 ; i < n ; i++ )
        if(v[i] <= v[i-1]) {
            if(used)
                return false;
            used = true;
            if(i > 1 and v[i] <= v[i-2])
                v[i] = v[i-1];
        }
    return true;
}
