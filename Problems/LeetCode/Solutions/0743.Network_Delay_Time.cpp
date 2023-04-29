class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int s) {
        int m = (int) times.size();
        vector< vector< pair<int,int> > > adj(N, vector< pair<int,int> >(0));
        for( int i = 0 , u,v,w ; i < m ; i++ ) {
            u = times[i][0]-1;
            v = times[i][1]-1;
            w = times[i][2];
            adj[u].push_back( make_pair(v,w) );
        }
        bool mark[N];
        memset(mark,0,sizeof(mark));
        int visited = 0, maxDist = 0;
        set< pair<int,int> > dists;
        set< pair<int,int> >::iterator iter;
        dists.insert( make_pair(0,--s) );
        while( !dists.empty() && visited < N ) {
            iter = dists.begin();
            pair<int,int> p = (*iter);
            dists.erase(iter);
            int u = p.second;
            int d = p.first;
            if(mark[u])
                continue;
            mark[u] = true;
            visited++;
            maxDist = d;
            for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if(!mark[v])
                    dists.insert( make_pair(d+w,v) );
            }
        }
        if(visited < N)
            return -1;
        else
            return maxDist;
    }
};
