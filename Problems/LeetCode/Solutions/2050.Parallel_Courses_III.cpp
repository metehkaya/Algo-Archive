#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m = relations.size();
        vector<int> indeg(n,0);
        vector<int> adj[n];
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        for( int i = 0 ; i < m ; i++ ) {
            int u = relations[i][0]-1;
            int v = relations[i][1]-1;
            adj[u].pb(v);
            indeg[v]++;
        }
        for( int i = 0 ; i < n ; i++ )
            if(indeg[i] == 0)
                heap.push(pi(time[i],i));
        int ans;
        while(!heap.empty()) {
            pi temp = heap.top();
            heap.pop();
            int t = temp.fi;
            int u = temp.se;
            ans = t;
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i];
                if(--indeg[v] == 0)
                    heap.push(pi(t+time[v],v));
            }
        }
        return ans;
    }
};
