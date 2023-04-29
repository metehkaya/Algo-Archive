#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    static const int maxn = 30000;
    static const int maxv = 100001;
    int n,m,k;
    int group[maxn];
    int idxprime[maxv];
    bool notprime[maxv];
    vector<int> primes;
    vector<int> indices[maxv];
    vector<int> adj[maxn];
    void dfs(int u , int m) {
        group[u] = m;
        int sz = adj[u].size();
        for( int i = 0 ; i < sz ; i++ ) {
            int v = adj[u][i];
            if(!group[v])
                dfs(v,m);
        }
    }
    bool gcdSort(vector<int>& ar) {
        n = ar.size();
        notprime[0] = notprime[1] = true;
        for( int i = 2 ; i < maxv ; i++ )
            if(!notprime[i]) {
                idxprime[i] = k++;
                primes.pb(i);
                if(i <= maxv/i)
                    for( int j = i*i ; j < maxv ; j += i )
                        notprime[j] = true;
            }
        for( int i = 0 ; i < n ; i++ ) {
            int num = ar[i];
            for( int j = 0 ; j < k && primes[j]*primes[j] <= ar[i] && primes[j] < num ; j++ )
                if(ar[i] % primes[j] == 0) {
                    indices[j].pb(i);
                    while(num % primes[j] == 0)
                        num /= primes[j];
                }
            if(num > 1)
                indices[idxprime[num]].pb(i);
        }
        for( int i = 0 ; i < k ; i++ ) {
            int sz = indices[i].size();
            for( int j = 0 ; j < sz-1 ; j++ ) {
                int u = indices[i][j];
                int v = indices[i][j+1];
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        for( int i = 0 ; i < n ; i++ )
            if(!group[i])
                dfs(i,++m);
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ )
            v.pb(pi(ar[i],i));
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n ; i++ ) {
            int x = v[i].se;
            if(group[i] != group[x])
                return false;
        }
        return true;
    }
};