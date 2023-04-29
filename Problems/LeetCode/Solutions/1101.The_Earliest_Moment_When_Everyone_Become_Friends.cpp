class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int comp = n;
        vector<int> lvl(n,0);
        vector<int> dad(n,-1);
        int m = logs.size();
        sort(logs.begin() , logs.end());
        for( int i = 0 ; i < m ; i++ ) {
            int u = logs[i][1];
            int v = logs[i][2];
            while(dad[u] != -1)
                u = dad[u];
            while(dad[v] != -1)
                v = dad[v];
            if(u == v)
                continue;
            comp--;
            if(lvl[u] <= lvl[v]) {
                dad[u] = v;
                if(lvl[u] == lvl[v])
                    lvl[v]++;
            }
            else
                dad[v] = u;
            if(comp == 1)
                return logs[i][0];
        }
        return -1;
    }
};