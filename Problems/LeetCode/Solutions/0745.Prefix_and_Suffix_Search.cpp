typedef long long LL;
typedef pair<LL,LL> pi;

class WordFilter {
public:
    map<pi,int> mp[10][10];
    LL mod = (LL) 1e9+7;
    WordFilter(vector<string>& words) {
        int n = words.size();
        for( int i = 0 ; i < n ; i++ ) {
            int len = words[i].length();
            LL p = 0;
            vector<LL> ps;
            for( int j = 0 ; j < len ; j++ ) {
                p = (26*p+words[i][j]-'a') % mod;
                ps.push_back(p);
            }
            LL s = 0;
            vector<LL> ss;
            for( int j = 0 ; j < len ; j++ ) {
                s = (26*s+words[i][len-1-j]-'a') % mod;
                ss.push_back(s);
            }
            for( int j = 0 ; j < len ; j++ )
                for( int k = 0 ; k < len ; k++ )
                    mp[j][k][pi(ps[j],ss[k])] = i;
        }
    }
    int f(string prefix, string suffix) {
        int lenp = prefix.length();
        int lens = suffix.length();
        LL p = 0 , s = 0;
        for( int i = 0 ; i < lenp ; i++ )
            p = (26*p+prefix[i]-'a') % mod;
        for( int i = 0 ; i < lens ; i++ )
            s = (26*s+suffix[lens-1-i]-'a') % mod;
        map<pi,int>::iterator it = mp[lenp-1][lens-1].find(pi(p,s));
        if(it == mp[lenp-1][lens-1].end())
            return -1;
        return (*it).second;
    }
};