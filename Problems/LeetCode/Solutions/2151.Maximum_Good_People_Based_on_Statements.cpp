class Solution {
public:
    int maximumGood(vector<vector<int>>& ar) {
        int n = ar.size() , ans = 0;
        for( int bmask = 1 ; bmask < (1<<n) ; bmask++ ) {
            int cnt = 0;
            bool ok = true;
            for( int i = 0 ; i < n && ok ; i++ )
                if(bmask & (1<<i)) {
                    cnt++;
                    for( int j = 0 ; j < n && ok ; j++ )
                        if(ar[i][j] == 1 && (bmask & (1<<j)) == 0)
                            ok = false;
                        else if(ar[i][j] == 0 && (bmask & (1<<j)) > 0)
                            ok = false;
                }
            if(ok)
                ans = max(ans,cnt);
        }
        return ans;
    }
};
