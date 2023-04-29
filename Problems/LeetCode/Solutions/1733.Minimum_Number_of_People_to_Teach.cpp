class Solution {
public:
    static const int maxnm = 500;
    bool lang[maxnm][maxnm];
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        for( int i = 0 ; i < m ; i++ )
            for( int j = 0 ; j < languages[i].size() ; j++ )
                lang[i][languages[i][j]-1] = true;
        int ans = m;
        for( int l = 0 ; l < n ; l++ ) {
            set<int> s;
            for( int i = 0 ; i < friendships.size() ; i++ ) {
                int u = friendships[i][0]-1;
                int v = friendships[i][1]-1;
                bool ok = false;
                for( int j = 0 ; j < n ; j++ )
                    if(lang[u][j] && lang[v][j]) {
                        ok = true;
                        break;
                    }
                if(!ok) {
                    if(!lang[u][l])
                        s.insert(u);
                    if(!lang[v][l])
                        s.insert(v);
                }
            }
            ans = min(ans,(int)s.size());
        }
        return ans;
    }
};