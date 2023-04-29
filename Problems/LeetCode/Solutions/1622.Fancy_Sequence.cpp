#define fi first
#define se second
typedef long long LL;
typedef pair<LL,LL> pi;

class Fancy {
public:
    int n,cnt;
    static const int maxs = 320;
    static const int maxn = 100000;
    const int mod = (int) 1e9+7;
    pi ar[maxn];
    pi block[maxs];
    int last[maxn];
    vector<int> v;
    Fancy() {
        n = cnt = 0;
    }
    void append(int val) {
        v.push_back(val);
        last[n++] = cnt;
    }
    pi merge(pi a , pi b) {
        a.fi = (a.fi*b.fi) % mod;
        a.se = (a.se*b.fi) % mod;
        a.se = (a.se+b.se) % mod;
        return a;
    }
    void blockTask() {
        if(cnt % maxs == 0) {
            int id = cnt/maxs-1;
            pi p = pi(1,0);
            for( int i = cnt-maxs ; i < cnt ; i++ )
                p = merge(p,ar[i]);
            block[id] = p;
        }
    }
    void addAll(int inc) {
        ar[cnt++] = pi(1,inc);
        blockTask();
    }
    void multAll(int m) {
        ar[cnt++] = pi(m,0);
        blockTask();
    }
    int getIndex(int idx) {
        if(idx >= n)
            return -1;
        if(last[idx] == cnt)
            return v[idx];
        int l = last[idx];
        int r = cnt-1;
        pi p = pi(0,v[idx]);
        int lid = l/maxs;
        int rid = r/maxs;
        if(lid == rid)
            for( int i = l ; i <= r ; i++ )
                p = merge(p,ar[i]);
        else {
            int x = maxs*(lid+1)-1;
            int y = maxs*rid;
            for( int i = l ; i <= x ; i++ )
                p = merge(p,ar[i]);
            for( int i = lid+1 ; i < rid ; i++ )
                p = merge(p,block[i]);
            for( int i = y ; i <= r ; i++ )
                p = merge(p,ar[i]);
        }
        return p.se;
    }
};