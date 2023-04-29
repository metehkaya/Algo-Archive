class Solution {
public:
    int numSquares(int n) {
        vector<int> dist(n+1,INT_MAX);
        dist[0] = 0;
        for( int i = 0 ; i < n ; i++ )
            if(dist[i] != INT_MAX)
                for( int j = 1 ; i+j*j <= n ; j++ )
                    dist[i+j*j] = min(dist[i+j*j],dist[i]+1);
        return dist[n];
    }
};