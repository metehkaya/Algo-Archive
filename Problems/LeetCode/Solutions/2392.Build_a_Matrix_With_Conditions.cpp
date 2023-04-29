class Solution {
public:
    static const int maxk = 400;
    int k;
    bool possible = true;
    int ord[maxk][2];
    int indeg[maxk][2];
    vector<int> adj[maxk][2];
    void topsort(vector<vector<int>> conditions , int type) {
        int sz = conditions.size();
        for( int i = 0 ; i < sz ; i++ ) {
            int u = conditions[i][0]-1;
            int v = conditions[i][1]-1;
            indeg[v][type]++;
            adj[u][type].push_back(v);
        }
        int cnt = 0;
        queue<int> q;
        for( int i = 0 ; i < k ; i++ )
            if(!indeg[i][type])
                q.push(i);
        for( int i = 0 ; i < k ; i++ ) {
            if(q.empty()) {
                possible = false;
                return;
            }
            int u = q.front();
            q.pop();
            ord[u][type] = i;
            int deg = adj[u][type].size();
            for( int j = 0 ; j < deg ; j++ ) {
                int v = adj[u][type][j];
                if(--indeg[v][type] == 0)
                    q.push(v);
            }
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        this->k = k;
        memset(ord,-1,sizeof(ord));
        topsort(rowConditions,0);
        topsort(colConditions,1);
        if(!possible) {
            vector<vector<int>> ans;
            return ans;
        }
        vector<vector<int>> ans(k,vector<int>(k,0));
        for( int i = 0 ; i < k ; i++ )
            ans[ord[i][0]][ord[i][1]] = i+1;
        return ans;
    }
};
