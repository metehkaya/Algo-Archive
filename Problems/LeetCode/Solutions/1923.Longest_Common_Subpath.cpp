typedef long long LL;

class Solution {
public:
    const LL base = 100003;
    const LL mod = 1000000000039;
    bool check(vector<vector<int>>& paths , LL pw, int len) {
        int n = paths.size();
        set<LL> s;
        for( int i = 0 ; i < n ; i++ ) {
            set<LL> s_new;
            int m = paths[i].size();
            LL curr = 0;
            for( int j = 0 ; j < len ; j++ ) {
                curr = (base * curr) % mod;
                curr = (curr + paths[i][j]) % mod;
            }
            if(i == 0)
                s.insert(curr);
            else if(s.count(curr))
                s_new.insert(curr);
            for( int j = len ; j < m ; j++ ) {
                LL val = (paths[i][j-len] * pw) % mod;
                curr = (curr - val + mod) % mod;
                curr = (curr * base + paths[i][j]) % mod;
                if(i == 0)
                    s.insert(curr);
                else if(s.count(curr))
                    s_new.insert(curr);
            }
            if(i)
                s = s_new;
            if(s.empty())
                return false;
        }
        return true;
    }
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int r = INT_MAX;
        for(auto path : paths)
            r = min(r,(int)path.size());
        vector<LL> pw(r,0);
        pw[0] = 1;
        for( int i = 1 ; i < r ; i++ )
            pw[i] = (pw[i-1]*base) % mod;
        int l = 1 , ans = 0;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(paths, pw[mid-1], mid))
                ans = mid , l = mid+1;
            else
                r = mid-1;
        }
        return ans;
    }
};
