class Solution {
public:
    int diameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u=e[0] , v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        for( int i = 0 ; i < n ; i++ )
            if(deg[i] == 1)
                q.push(i);
        int lvl = 0, left = n;
        while(left > 2) {
            queue<int> q_next;
            while(!q.empty()) {
                left--;
                int u = q.front();
                q.pop();
                for(int v : adj[u])
                    if(--deg[v] == 1)
                        q_next.push(v);
            }
            q = q_next;
            lvl++;
        }
        return (left == 2) ? 2*lvl+1 : 2*lvl;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);
        return max({d1, d2, (d1+1)/2 + (d2+1)/2 + 1});
    }
};