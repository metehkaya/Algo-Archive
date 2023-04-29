class ThroneInheritance {
public:
    int n;
    static const int maxn = 100003;
    vector<string> names;
    vector<int> adj[maxn];
    bool deaths[maxn];
    map<string,int> toid;
    ThroneInheritance(string kingName) {
        n = 1;
        names.push_back(kingName);
        toid[kingName] = 0;
    }
    void birth(string parentName, string childName) {
        names.push_back(childName);
        adj[toid[parentName]].push_back(n);
        toid[childName] = n;
        n++;
    }
    void death(string name) {
        deaths[toid[name]] = true;
    }
    void dfs(int u , vector<string>& ans) {
        if(!deaths[u])
            ans.push_back(names[u]);
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            dfs(adj[u][i],ans);
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(0,ans);
        return ans;
    }
};
