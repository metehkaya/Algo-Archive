class Solution {
public:
    const int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int bfs(int rs, int cs, int re, int ce, vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        bool mark[n][m];
        memset(mark,false,sizeof(mark));
        queue<pair<pair<int,int>,int>>Q;
        mark[rs][cs] = true;
        Q.push(make_pair(make_pair(rs,cs),0));
        while(!Q.empty()) {
            pair<pair<int,int>,int> p = Q.front();
            Q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int d = p.second;
            if( r == re && c == ce )
                return d;
            for( int i = 0 ; i < 4 ; i++ ) {
                int r2 = r+DIR[i][0];
                int c2 = c+DIR[i][1];
                if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)
                    continue;
                if(mark[r2][c2] || ar[r2][c2] == 0)
                    continue;
                mark[r2][c2] = true;
                Q.push( make_pair( make_pair(r2,c2) , d+1 ) );
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& ar) {
        if(ar.size() == 0 || ar[0].size() == 0)
            return -1;
        int n = ar.size();
        int m = ar[0].size();
        vector< pair< int , pair<int,int> > > locs;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] > 1 )
                    locs.push_back( make_pair( ar[i][j] , make_pair(i,j) ) );
        sort( locs.begin() , locs.end() );
        if(locs.size() == 0)
            return 0;
        int ans = bfs(0,0,locs[0].second.first,locs[0].second.second,ar);
        if(ans == -1)
            return -1;
        for( int i = 1 ; i < locs.size() ; i++ ) {
            int rs = locs[i-1].second.first;
            int cs = locs[i-1].second.second;
            int re = locs[i].second.first;
            int ce = locs[i].second.second;
            ar[rs][cs] = 1;
            int cost = bfs(rs,cs,re,ce,ar);
            if(cost == -1)
                return -1;
            ans += cost;
        }
        return ans;
    }
};