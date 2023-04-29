class Solution {
public:
    const int maxv = 100001;
    int largestComponentSize(vector<int>& ar) {
        int n = ar.size() , p = 0;
        int pr[maxv];
        vector<int> primes;
        memset(pr,-1,sizeof(pr));
        for( int i = 2 ; i < maxv ; i++ )
            if(pr[i] == -1) {
                for( int j = i ; j < maxv ; j += i )
                    pr[j] = p;
                p++;
                primes.push_back(i);
            }
        vector<int> idxs[p];
        for( int i = 0 ; i < n ; i++ ) {
            int last = -1;
            while(ar[i] > 1) {
                int idx = pr[ar[i]];
                if(last != idx)
                    last = idx , idxs[idx].push_back(i);
                ar[i] /= primes[idx];
            }
        }
        int ans = 1;
        vector<int> sz(n,1);
        vector<int> dad(n,-1);
        for( int i = 0 ; i < p ; i++ ) {
            int nsz = idxs[i].size();
            for( int j = 0 ; j < nsz-1 ; j++ ) {
                int u = idxs[i][j] , v = idxs[i][j+1];
                while(dad[u] != -1)
                    u = dad[u];
                while(dad[v] != -1)
                    v = dad[v];
                if(u != v) {
                    if(sz[u] < sz[v])
                        dad[u] = v , sz[v] += sz[u];
                    else
                        dad[v] = u , sz[u] += sz[v];
                    ans = max(ans,max(sz[u],sz[v]));
                }
            }
        }
        return ans;
    }
};