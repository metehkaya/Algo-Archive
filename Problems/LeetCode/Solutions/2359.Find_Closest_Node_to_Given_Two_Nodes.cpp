class Solution {
public:
    int n;
    vector<int> edges;
    int dist[2][100000];
    void dfs(int u , int k , int d) {
        dist[k][u] = d;
        if(edges[u] == -1)
            return;
        int v = edges[u];
        if(dist[k][v] != -1)
            return;
        dfs(v,k,d+1);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        this->edges = edges;
        memset(dist,-1,sizeof(dist));
        dfs(node1,0,0);
        dfs(node2,1,0);
        int ans = -1 , dmin = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            if(dist[0][i] != -1 && dist[1][i] != -1) {
                int d = max(dist[0][i],dist[1][i]);
                if(d < dmin) {
                    dmin = d;
                    ans = i;
                }
            }
        return ans;
    }
};
