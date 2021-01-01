class Solution {
public:
    int k = 0;
    int mark[26];
    bool G[26][26];
    vector<char> mins;
    int dfs(int u) {
        mark[u] = k;
        int cmin = u;
        for( int i = 0 ; i < 26 ; i++ )
            if(G[u][i] && mark[i] == -1)
                cmin = min(cmin,dfs(i));
        return cmin;
    }
    string smallestEquivalentString(string a, string b, string s) {
        int n = a.length();
        memset(G,false,sizeof(G));
        for( int i = 0 ; i < n ; i++ )
            G[a[i]-'a'][b[i]-'a'] = G[b[i]-'a'][a[i]-'a'] = true;
        memset(mark,-1,sizeof(mark));
        for( int i = 0 ; i < 26 ; i++ )
            if(mark[i] == -1) {
                int cmin = dfs(i);
                mins.push_back('a'+cmin);
                k++;
            }
        n = s.length();
        for( int i = 0 ; i < n ; i++ )
            s[i] = mins[mark[s[i]-'a']];
        return s;
    }
};