class Solution {
public:
    int n,w;
    vector<int> ans;
    map<int, vector<int> > children;
    void dfs(int u , bool add) {
        if(u == w)
            add = true;
        if(add)
            ans.push_back(u);
        vector<int> v = children[u];
        int deg = v.size();
        for( int i = 0 ; i < deg ; i++ )
            dfs(v[i],add);
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        w = kill;
        n = pid.size();
        for( int i = 0 ; i < n ; i++ )
            children[ppid[i]].push_back(pid[i]);
        dfs(0,false);
        return ans;
    }
};