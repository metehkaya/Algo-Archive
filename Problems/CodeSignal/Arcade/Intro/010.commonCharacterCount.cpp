int solution(string s1, string s2) {
    vector<vector<int>> cnt(2,vector<int>(26,0));
    for(char c : s1)
        cnt[0][c-'a']++;
    for(char c : s2)
        cnt[1][c-'a']++;
    int ans = 0;
    for( int i = 0 ; i < 26 ; i++ )
        ans += min(cnt[0][i],cnt[1][i]);
    return ans;
}
