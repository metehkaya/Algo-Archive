class Solution {
public:
    void dfs(int root , int u , vector<vector<int>>& adj , int& mark) {
        if(root != u)
            mark |= (1<<u);
        for( int i = 0 ; i < (int) adj[u].size() ; i++ ) {
            int v = adj[u][i];
            if(mark & (1<<v))
                continue;
            dfs(root,v,adj,mark);
        }
    }
    void f(int i , int curr , int cnt , int bmask , int n , int k , vector<int>& goo , vector<int>& mark) {
        if(i == n) {
            goo.push_back(curr);
            return;
        }
        if(bmask & (1<<i)) {
            f(i+1,curr,cnt,bmask,n,k,goo,mark);
            return;
        }
        f(i+1,curr,cnt,bmask,n,k,goo,mark);
        if(cnt < k && (mark[i] & bmask) == mark[i])
            f(i+1,(curr|(1<<i)),cnt+1,bmask,n,k,goo,mark);
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(n);
        for( int i = 0 ; i < edges.size() ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v-1].push_back(u-1);
        }
        vector<int> mark(n,0);
        for( int i = 0 ; i < n ; i++ )
            dfs(i,i,adj,mark[i]);
        int N = (1<<n);
        vector<vector<int>> goo(N);
        for( int i = 0 ; i < N ; i++ )
            f(0,0,0,i,n,k,goo[i],mark);
        queue<int> Q;
        vector<int> dist(N,-1);
        Q.push(0);
        dist[0] = 0;
        while(!Q.empty()) {
            int bmask = Q.front();
            Q.pop();
            if(bmask == N-1)
                return dist[N-1];
            for( int i = 0 ; i < goo[bmask].size() ; i++ ) {
                int add = goo[bmask][i];
                int mask = (bmask | add);
                if(dist[mask] != -1)
                    continue;
                dist[mask] = dist[bmask] + 1;
                Q.push(mask);
            }
        }
        return -1;
    }
};