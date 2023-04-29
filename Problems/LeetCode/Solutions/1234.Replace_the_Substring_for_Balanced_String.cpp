class Solution {
public:
    int getMax(vector<int>& v) {
        int mx = 0;
        for( int i = 0 ; i < 4 ; i++ )
            mx = max(mx,v[i]);
        return mx;
    }
    int balancedString(string s) {
        int index[256];
        index['Q'] = 0;
        index['W'] = 1;
        index['E'] = 2;
        index['R'] = 3;
        vector<int> cnt(4,0);
        int n = s.length();
        int r = n;
        while(r > 0 && cnt[index[s[r-1]]] < n/4)
            cnt[index[s[--r]]]++;
        if(r == 0)
            return 0;
        int ans = r;
        for( int l = 0 ; l < n ; l++ ) {
            cnt[index[s[l]]]++;
            while(r < n && getMax(cnt) > n/4)
                cnt[index[s[r++]]]--;
            if(getMax(cnt) <= n/4)
                ans = min(ans , r-l-1);
        }
        return ans;
    }
};