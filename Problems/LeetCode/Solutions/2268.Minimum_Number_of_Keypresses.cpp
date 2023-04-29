class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> cnt(26,0);
        for(char c : s)
            cnt[c-'a']++;
        sort(cnt.begin(),cnt.end());
        reverse(cnt.begin(),cnt.end());
        int ans = 0;
        for( int i = 0 ; i < 26 ; i++ ) {
            int times = i/9+1;
            ans += times*cnt[i];
        }
        return ans;
    }
};
