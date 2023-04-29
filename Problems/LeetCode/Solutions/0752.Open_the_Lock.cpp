class Solution {
public:
    static const int maxn = 10000;
    int dist[maxn];
    vector<int> adj[maxn];
    int int2str(string& s) {
        int val = 0;
        int len = s.length();
        for( int i = 0 ; i < len ; i++ )
            val = 10*val + s[i]-'0';
        return val;
    }
    int openLock(vector<string>& deadends, string target) {
        for( int i = 0 ; i < maxn ; i++ ) {
            for( int v = 1 ; v < maxn ; v *= 10 ) {
                int rem = i % (10*v);
                int d = rem / v;
                int nxt = (d == 9) ? 0 : d+1;
                int valnxt = i + v * (nxt-d);
                adj[i].push_back(valnxt);
                int prv = (d == 0) ? 9 : d-1;
                int valprv = i + v * (prv-d);
                adj[i].push_back(valprv);
            }
        }
        memset(dist,-1,sizeof(dist));
        for( int i = 0 ; i < deadends.size() ; i++ )
            dist[int2str(deadends[i])] = -2;
        if(dist[0] == -2)
            return -1;
        queue<int> Q;
        Q.push(0);
        dist[0] = 0;
        int t = int2str(target);
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            if(u == t)
                return dist[u];
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i];
                if(dist[v] == -1) {
                    Q.push(v);
                    dist[v] = dist[u] + 1;
                }
            }
        }
        return -1;
    }
};