class Solution {
public:
    static const int maxs = (1<<15);
    int n,m;
    int dist[maxs];
    int get_idx_bmask(int r , int c) {
        return 1 << (r*m+c);
    }
    int removeOnes(vector<vector<int>>& v) {
        n = v.size() , m = v[0].size();
        int src = 0;
        vector<int> bmasks;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int bmask = 0;
                if(v[i][j])
                    src |= get_idx_bmask(i,j);
                for( int r = 0 ; r < n ; r++ )
                    for( int c = 0 ; c < m ; c++ )
                        if(r == i or c == j)
                            bmask |= get_idx_bmask(r,c);
                bmasks.push_back(bmask);
            }
        memset(dist,-1,sizeof(dist));
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int bmask = q.front();
            q.pop();
            if(bmask == 0)
                return dist[bmask];
            for( int idx = 0 ; idx < n*m ; idx++ ) {
                int cell_bmask = (1<<idx);
                if(bmask & cell_bmask) {
                    int new_bmask = bmask - (bmask & bmasks[idx]);
                    if(dist[new_bmask] == -1) {
                        q.push(new_bmask);
                        dist[new_bmask] = dist[bmask]+1;
                    }
                }
            }
        }
        return -1;
    }
};
