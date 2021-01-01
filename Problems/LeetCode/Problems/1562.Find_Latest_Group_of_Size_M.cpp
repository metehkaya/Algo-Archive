class Solution {
public:
    int findLatestStep(vector<int>& ar, int m) {
        int n = ar.size() , ans = -1;
        vector<int> dad(n+2);
        vector<int> sz(n+2);
        for( int i = 0 ; i <= n+1 ; i++ )
            dad[i] = i , sz[i] = 0;
        vector<int> cnt(n+1,0);
        cnt[0] = n;
        vector<int> curr(n+2,0);
        for( int i = 0 ; i < n ; i++ ) {
            int x = ar[i];
            curr[x] = 1;
            int l = x-1 , cntl = 0;
            int r = x+1 , cntr = 0;
            if(curr[l]) {
                while(l != dad[l])
                    l = dad[l];
                cntl = sz[l];
            }
            if(curr[r]) {
                while(r != dad[r])
                    r = dad[r];
                cntr = sz[r];
            }
            cnt[0]--;
            if(cntl)
                cnt[cntl]--;
            if(cntr)
                cnt[cntr]--;
            cnt[cntl+cntr+1]++;
            if(cnt[m])
                ans = i+1;
            if(max(cntl,cntr) == 0)
                sz[x] = 1;
            else if(cntl > cntr) {
                dad[r] = l;
                dad[x] = l;
                sz[l] = cntl+cntr+1;
            }
            else {
                dad[l] = r;
                dad[x] = r;
                sz[r] = cntl+cntr+1;
            }
        }
        return ans;
    }
};