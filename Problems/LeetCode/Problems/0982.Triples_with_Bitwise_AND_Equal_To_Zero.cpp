class Solution {
public:
    const int maxv = (1<<16);
    int countTriplets(vector<int>& ar) {
        int n = ar.size();
        vector<int> cnt(maxv,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < maxv ; j++ )
                if((ar[i] & j) == 0)
                    cnt[j]++;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                ans += cnt[ar[i]&ar[j]];
        return ans;
    }
};