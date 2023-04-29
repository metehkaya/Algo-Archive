class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        for( int i = 0 ; i < n ; i++ )
            freq[s[i]-'a']++;
        vector<int> cnt(n+1,0);
        for( int i = 0 ; i < 26 ; i++ )
            if(freq[i])
                cnt[freq[i]]++;
        int ans = 0;
        for( int i = n , curr = 0 ; i >= 0 ; i-- ) {
            ans += curr;
            curr += cnt[i];
            if(curr)
                curr--;
        }
        return ans;
    }
};