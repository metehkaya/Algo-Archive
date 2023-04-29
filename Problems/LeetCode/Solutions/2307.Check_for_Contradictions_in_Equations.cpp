class Solution {
public:
    const double eps = 1e-6;
    static const int maxn = 200;
    bool mark[maxn];
    double ans[maxn];
    vector<pair<int,double>> adj[maxn];
    bool f(int u , double val) {
        ans[u] = val;
        mark[u] = true;
        for(auto& e : adj[u]) {
            int v = e.first;
            double w = e.second;
            double val_v = val / w;
            if(!mark[v] and f(v,val_v))
                return true;
            else if(mark[v] and abs(val_v-ans[v]) > eps)
                return true;
        }
        return false;
    }
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        int n = 0;
        unordered_map<string,int> hash2id;
        for(auto& eq : equations) {
            if(hash2id.find(eq[0]) == hash2id.end())
                hash2id[eq[0]] = n++;
            if(hash2id.find(eq[1]) == hash2id.end())
                hash2id[eq[1]] = n++;
        }
        int m = equations.size();
        for( int i = 0 ; i < m ; i++ ) {
            auto eq = equations[i];
            double val = values[i];
            int u = hash2id[eq[0]] , v = hash2id[eq[1]];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1/val});
        }
        memset(mark,false,sizeof(mark));
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i] and f(i,1))
                return true;
        return false;
    }
};
