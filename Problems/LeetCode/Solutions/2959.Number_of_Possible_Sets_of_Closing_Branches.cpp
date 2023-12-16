class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        for( int bmask = 0 ; bmask < (1<<n) ; bmask++ ) {
            vector<int> v;
            for( int i = 0 ; i < n ; i++ )
                if(bmask & (1<<i))
                    v.push_back(i);
            int dist[n][n];
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < n ; j++ )
                    dist[i][j] = (i != j) * (maxDistance+1);
            for(auto e : roads)
                if((bmask & (1<<e[0])) and (bmask & (1<<e[1]))) {
                    dist[e[0]][e[1]] = min(dist[e[0]][e[1]],e[2]);
                    dist[e[1]][e[0]] = min(dist[e[1]][e[0]],e[2]);
                }
            for(int c : v)
                for(int a : v)
                    for(int b : v)
                        dist[a][b] = min(dist[a][b],dist[a][c]+dist[c][b]);
            int add = 1;
            for(int a : v)
                for(int b : v)
                    if(dist[a][b] > maxDistance)
                        add = 0;
            ans += add;
        }
        return ans;
    }
};
