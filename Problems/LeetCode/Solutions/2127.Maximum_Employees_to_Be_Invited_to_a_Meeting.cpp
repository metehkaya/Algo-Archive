class Solution {
public:
    static const int maxn = 100000;
    int max_chain=0,dfs_cnt=0;
    int dfs_id[maxn];
    bool is_double[maxn];
    int vertex_order[maxn];
    int prev_max[maxn];
    vector<int> goo[maxn];
    void dfs(int u , int order , vector<int>& comp, vector<int>& fav) {
        comp.push_back(u);
        dfs_id[u] = dfs_cnt;
        vertex_order[u] = order;
        int v = fav[u];
        if(dfs_id[v] == -1)
            dfs(v,order+1,comp,fav);
        else if(dfs_id[v] == dfs_cnt) {
            int order_v = vertex_order[v];
            int len = order-order_v+1;
            if(len > 2)
                max_chain = max(max_chain,len);
            for( int i = 0 ; i < order_v ; i++ ) {
                int w = comp[i];
                goo[w] = {v, order_v-i};
            }
            for( int i = order_v ; i <= order ; i++ ) {
                int w = comp[i];
                goo[w] = {w, 0};
            }
        }
        else {
            int final_node = goo[v][0];
            int dist_to_final_node = goo[v][1];
            for( int i = 0 ; i <= order ; i++ ) {
                int w = comp[i];
                goo[w] = {final_node, dist_to_final_node+order-i+1};
            }
        }
    }
    int maximumInvitations(vector<int>& fav) {
        memset(dfs_id,-1,sizeof(dfs_id));
        memset(vertex_order,-1,sizeof(vertex_order));
        memset(is_double,false,sizeof(is_double));
        memset(prev_max,0,sizeof(prev_max));
        int n = fav.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(fav[fav[i]] == i)
                is_double[i] = true;
        for( int i = 0 ; i < n ; i++ )
            if(dfs_id[i] == -1) {
                vector<int> comp;
                dfs(i,0,comp,fav);
                dfs_cnt++;
            }
        for( int i = 0 ; i < n ; i++ ) {
            int j = goo[i][0];
            int d = goo[i][1];
            prev_max[j] = max(prev_max[j],d);
        }
        for( int i = 0 ; i < n ; i++ )
            if(is_double[i])
                ans += prev_max[i]+1;
        ans = max(ans,max_chain);
        return ans;
    }
};
