class Solution {
public:
    int maxLength(vector<string>& ar) {
        int n = ar.size() , ans = 0;
        int N = (1<<n);
        vector<vector<int>> cnt(N,vector<int>(26,0));
        for( int bmask = 1 ; bmask < N ; bmask++ ) {
            int bm = (bmask & (-bmask));
            cnt[bmask] = cnt[bmask-bm];
            string s = ar[log2(bm)];
            for( int i = 0 ; i < s.length() ; i++ )
                cnt[bmask][s[i]-'a']++;
            int mx = 0 , sum = 0;
            for( int i = 0 ; i < 26 ; i++ )
                sum += cnt[bmask][i] , mx = max(mx,cnt[bmask][i]);
            if(mx <= 1)
                ans = max(ans,sum);
        }
        return ans;
    }
};