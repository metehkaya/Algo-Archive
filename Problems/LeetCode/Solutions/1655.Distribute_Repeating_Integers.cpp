class Solution {
public:
    const static int MAXN = 50;
    const static int MAXM = 1024;
    int n,m,M;
    int sum[MAXM];
    bool mark[MAXN][MAXM];
    vector<int> freqs;
    vector<int> v[MAXM];
    bool f(int idx , int bmask) {
        if(bmask == M-1)
            return true;
        if(idx == n)
            return false;
        if(mark[idx][bmask])
            return false;
        mark[idx][bmask] = true;
        int sz = v[bmask].size();
        for( int i = 0 ; i < sz ; i++ ) {
            int add = v[bmask][i];
            if(sum[add] <= freqs[idx] && f(idx+1,bmask+add))
                return true;
        }
        return false;
    }
    bool canDistribute(vector<int>& ar, vector<int>& quantity) {
        n = ar.size();
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]]++;
        for(auto it : mp)
            freqs.push_back(it.second);
        n = freqs.size();
        m = quantity.size();
        M = (1<<m);
        for( int i = 0 ; i < M ; i++ ) {
            sum[i] = 0;
            for( int j = 0 ; j < m ; j++ )
                if(i & (1<<j))
                    sum[i] += quantity[j];
            for( int j = 0 ; j < M ; j++ )
                if((i&j) == 0)
                    v[i].push_back(j);
        }
        memset(mark,false,sizeof(mark));
        return f(0,0);
    }
};