class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<set<int>> adj(n);
        vector<int> deg(n,0);
        for(auto e : edges) {
            int u = e[0]-1;
            int v = e[1]-1;
            adj[u].insert(v);
            adj[v].insert(u);
            deg[u] ^= 1;
            deg[v] ^= 1;
        }
        vector<int> odds;
        for( int i = 0 ; i < n ; i++ )
            if(deg[i])
                odds.push_back(i);
        int n_odds = odds.size();
        if(n_odds == 1 or n_odds == 3 or n_odds > 4)
            return false;
        else if(n_odds == 0)
            return true;
        else if(n_odds == 2) {
            int u = odds[0];
            int v = odds[1];
            if(!adj[u].count(v))
                return true;
            for( int i = 0 ; i < n ; i++ )
                if(!adj[u].count(i) and !adj[v].count(i))
                    return true;
            return false;
        }
        else {
            int s = odds[0];
            int u = odds[1];
            int v = odds[2];
            int w = odds[3];
            if(!adj[s].count(u) and !adj[v].count(w))
                return true;
            if(!adj[s].count(v) and !adj[u].count(w))
                return true;
            if(!adj[s].count(w) and !adj[u].count(v))
                return true;
            return false;
        }
        return false;
    }
};
