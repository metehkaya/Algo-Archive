class Solution {
public:
    int n;
    int cnt[30];
    int totalHammingDistance(vector<int>& ar) {
        n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < 30 ; j++ )
                if((ar[i] & (1<<j)))
                    cnt[j]++;
        int ans = 0;
        for( int i = 0 ; i < 30 ; i++ )
            ans += cnt[i] * (n-cnt[i]);
        return ans;
    }
};