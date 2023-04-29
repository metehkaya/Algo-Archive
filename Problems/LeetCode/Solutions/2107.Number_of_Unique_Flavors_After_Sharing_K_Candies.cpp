class Solution {
public:
    static const int maxs = 100001;
    int cnt[maxs];
    int shareCandies(vector<int>& v, int k) {
        int n = v.size() , total = 0;
        if(k == n)
            return 0;
        memset(cnt,0,sizeof(cnt));
        for( int i = 0 ; i < n ; i++ )
            if(++cnt[v[i]] == 1)
                total++;
        if(k == 0)
            return total;
        for( int i = 0 ; i < k ; i++ )
            if(--cnt[v[i]] == 0)
                total--;
        int ans = total;
        for( int i = k ; i < n ; i++ ) {
            if(--cnt[v[i]] == 0)
                total--;
            if(++cnt[v[i-k]] == 1)
                total++;
            ans = max(ans,total);
        }
        return ans;
    }
};
