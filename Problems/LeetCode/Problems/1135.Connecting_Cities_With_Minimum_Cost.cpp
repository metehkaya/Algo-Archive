class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& ar) {
        int m = ar.size();
        for( int i = 0 ; i < m ; i++ )
            swap(ar[i][0],ar[i][2]);
        sort(ar.begin() , ar.end());
        int comp = n , total = 0;
        vector<int> lvl(n,0);
        vector<int> dad(n,-1);
        for( int i = 0 ; i < m ; i++ ) {
            int u = ar[i][1]-1;
            int v = ar[i][2]-1;
            while(dad[u] != -1)
                u = dad[u];
            while(dad[v] != -1)
                v = dad[v];
            if(u == v)
                continue;
            total += ar[i][0];
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