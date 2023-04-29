#define pb push_back

class Solution {
public:
    const static int maxn = 20000;
    map<int,int> mp;
    vector<int> adj[maxn];
    bool mark[maxn];
    int getbmask(string& s) {
        int bmask = 0;
        for(char c : s)
            bmask |= (1<<(c-'a'));
        return bmask;
    }
    void dfs(int u , int& cnt) {
        cnt++;
        mark[u] = true;
        for(int v : adj[u])
            if(!mark[v])
                dfs(v,cnt);
    }
    void add(int x , int u) {
        auto it = mp.find(x);
        if(it == mp.end())
            mp[x] = u;
        else {
            int v = it->second;
            if(u != v) {
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
    }
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        for( int i = 0 ; i < n ; i++ ) {
            int bmask = getbmask(words[i]);
            add(bmask,i);
            for( int k = 0 ; k < 26 ; k++ )
                if(bmask & (1<<k))
                    add(bmask^(1<<k),i);
        }
        memset(mark,false,sizeof(mark));
        vector<int> ans(2,0);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                int cnt = 0;
                dfs(i,cnt);
                ans[0]++;
                ans[1] = max(ans[1],cnt);
            }
        return ans;
    }
};
