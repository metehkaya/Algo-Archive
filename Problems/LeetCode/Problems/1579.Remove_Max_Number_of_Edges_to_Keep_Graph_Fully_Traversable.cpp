#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    bool merge(int u , int v , vector<int>& dad , vector<int>& cnt) {
        bool ok = false;
        while(dad[u] != -1)
            u = dad[u];
        while(dad[v] != -1)
            v = dad[v];
        if(u != v) {
            ok = true;
            if(cnt[u] < cnt[v]) {
                cnt[v] += cnt[u];
                dad[u] = v;
            }
            else {
                cnt[u] += cnt[v];
                dad[v] = u;
            }
        }
        return ok;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> dad1(n,-1);
        vector<int> dad2(n,-1);
        vector<int> cnt1(n,1);
        vector<int> cnt2(n,1);
        vector<pi> e0,e1,e2;
        int m = edges.size() , add = 0;
        for( int i = 0 ; i < m ; i++ ) {
            if(edges[i][0] == 3)
                e0.pb(pi(edges[i][1]-1,edges[i][2]-1));
            else if(edges[i][0] == 1)
                e1.pb(pi(edges[i][1]-1,edges[i][2]-1));
            else
                e2.pb(pi(edges[i][1]-1,edges[i][2]-1));
        }
        for( int i = 0 ; i < e0.size() ; i++ ) {
            bool ok = false;
            int u = e0[i].fi;
            int v = e0[i].se;
            if(merge(u,v,dad1,cnt1))
                ok = true;
            if(merge(u,v,dad2,cnt2))
                ok = true;
            if(ok)
                add++;
        }
        for( int i = 0 ; i < e1.size() ; i++ ) {
            int u = e1[i].fi;
            int v = e1[i].se;
            if(merge(u,v,dad1,cnt1))
                add++;
        }
        for( int i = 0 ; i < e2.size() ; i++ ) {
            int u = e2[i].fi;
            int v = e2[i].se;
            if(merge(u,v,dad2,cnt2))
                add++;
        }
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            if(cnt1[i] == n)
                cnt++;
        for( int i = 0 ; i < n ; i++ )
            if(cnt2[i] == n)
                cnt++;
        if(cnt < 2)
            return -1;
        return m-add;
    }
};