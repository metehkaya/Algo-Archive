vector<string> solution(vector<string> v) {
    int max_len = 0 , n = v.size();
    for( int i = 0 ; i < n ; i++ )
        max_len = max(max_len,(int)v[i].length());
    vector<string> ans;
    for( int i = 0 ; i < n ; i++ )
        if(v[i].length() == max_len)
            ans.push_back(v[i]);
    return ans;
}
