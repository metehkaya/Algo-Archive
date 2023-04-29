class Solution {
public:
    int ans;
    int cnt[121];
    int numFriendRequests(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        for( int i = 1 ; i <= 120 ; i++ )
            for( int j = 1 ; j <= 120 ; j++ ) {
                bool ok = true;
                if(j <= i*0.5+7 || j > i || (j > 100 && i < 100))
                    ok = false;
                if(ok) {
                    if(i != j)
                        ans += cnt[i]*cnt[j];
                    else
                        ans += cnt[i]*(cnt[i]-1);
                }
            }
        return ans;
    }
};