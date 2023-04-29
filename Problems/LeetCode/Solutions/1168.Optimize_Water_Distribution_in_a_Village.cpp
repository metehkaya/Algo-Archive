typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int minCostToSupplyWater(int n, vi& wells, vii& pipes) {
        vii edges = pipes;
        int m = pipes.size();
        for( int i = 0 ; i < n ; i++ ) {
            vi v(3);
            v[0] = i+1 , v[1] = n+1 , v[2] = wells[i];
            edges.push_back(v);
        }
        for( int i = 0 ; i < n+m ; i++ )
            swap(edges[i][0] , edges[i][2]);
        int comp = n+1 , total = 0;
        vi lvl(n+2,0);
        vi dad(n+2,-1);
        sort(edges.begin() , edges.end());
        for( int i = 0 ; i < n+m ; i++ ) {
            int u = edges[i][1];
            int v = edges[i][2];
            while(dad[u] != -1)
                u = dad[u];
            while(dad[v] != -1)
                v = dad[v];
            if(u == v)
                continue;
            total += edges[i][0];
            if(--comp == 1)
                return total;
            if(lvl[u] <= lvl[v]) {
                dad[u] = v;
                if(lvl[u] == lvl[v])
                    lvl[v]++;
            }
            else
                dad[v] = u;
        }
        return -1;
    }
};