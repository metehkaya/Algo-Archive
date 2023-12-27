class Solution {
public:
    const int big = 1e9;
    long long minimumCost(string source, string target, vector<char>& s, vector<char>& t, vector<int>& c) {
        vector<vector<int>> dist(26,vector<int>(26,big));
        for( int i = 0 ; i < 26 ; i++ )
            dist[i][i] = 0;
        int n = c.size();
        for( int i = 0 ; i < n ; i++ )
            dist[s[i]-'a'][t[i]-'a'] = min(dist[s[i]-'a'][t[i]-'a'],c[i]);
        n = 26;
        for( int k = 0 ; k < n ; k++ )
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < n ; j++ )
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        n = source.length();
        long long ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int c1 = source[i]-'a';
            int c2 = target[i]-'a';
            if(dist[c1][c2] == big)
                return -1;
            ans += dist[c1][c2];
        }
        return ans;
    }
};
