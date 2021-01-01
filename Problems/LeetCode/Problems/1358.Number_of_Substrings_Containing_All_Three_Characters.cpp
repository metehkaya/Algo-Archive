class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> cnt(3,0);
        int ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while(j < n && (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0))
                cnt[s[j++]-'a']++;
            if(cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)
                break;
            ans += n-j+1;
            cnt[s[i]-'a']--;
        }
        return ans;
    }
};