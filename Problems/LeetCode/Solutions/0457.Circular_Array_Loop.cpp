class Solution {
public:
    bool dfs(int u , vector<int>& nxt , vector<bool>& st , vector<bool>& mark) {
        mark[u] = st[u] = true;
        int v = nxt[u];
        if(v != -1) {
            if(st[v])
                return true;
            if(dfs(v,nxt,st,mark))
                return true;
        }
        st[u] = false;
        return false;
    }
    bool circularArrayLoop(vector<int>& ar) {
        int n = ar.size();
        vector<int> nxt(n,-1);
        for( int i = 0 ; i < n ; i++ ) {
            int j = (i+ar[i])%n;
            if(j < 0)
                j += n;
            if(i == j)
                continue;
            if((ar[i] > 0 && ar[j] > 0) || (ar[i] < 0 && ar[j] < 0))
                nxt[i] = j;
        }
        vector<bool> st(n,false);
        vector<bool> mark(n,false);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i] && dfs(i,nxt,st,mark))
                return true;
        return false;
    }
};
