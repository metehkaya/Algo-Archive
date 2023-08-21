class Solution {
public:
    int n,m;
    int find_dad(int u, vector<int>& dad) {
        if(dad[u] == -1)
            return u;
        return dad[u] = find_dad(dad[u], dad);
    }
    bool add_edge(int u, int v, vector<int>& sz, vector<int>& dad) {
        u = find_dad(u,dad);
        v = find_dad(v,dad);
        if(u == v)
            return false;
        if(sz[u] > sz[v])
            swap(u,v);
        else if(sz[u] == sz[v])
            sz[v]++;
        dad[u] = v;
        return true;
    }
    int mst(vector<vector<int>>& edges, int edge_id, bool add) {
        vector<int> sz(n, 0);
        vector<int> dad(n, -1);
        int cost = 0 , n_edges = 0;
        if(add and add_edge(edges[edge_id][1], edges[edge_id][2], sz, dad)) {
            cost += edges[edge_id][0];
            n_edges++;
        }
        for( int i = 0 ; i < m ; i++ )
            if(i != edge_id and add_edge(edges[i][1], edges[i][2], sz, dad)) {
                cost += edges[i][0];
                n_edges++;
            }
        return n_edges == n-1 ? cost : INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        this->n = n;
        this->m = m;
        for( int i = 0 ; i < m ; i++ ) {
            swap(edges[i][0],edges[i][2]);
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end());
        vector<vector<int>> ans(2);
        int mst_cost = mst(edges, -1, false);
        for( int i = 0 ; i < m ; i++ ) {
            int id = edges[i][3];
            int mst_cost_1 = mst(edges, i, false);
            int mst_cost_2 = mst(edges, i, true);
            if(mst_cost_1 > mst_cost)
                ans[0].push_back(id);
            else if(mst_cost_2 == mst_cost)
                ans[1].push_back(id);
        }
        return ans;
    }
};
