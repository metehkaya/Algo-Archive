class Solution {
public:
    string sortString(string s) {
        int n = s.length();
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        string ans = "";
        while(n) {
            for( int i = 0 ; i < 26 ; i++ )
                if(cnt[i]) {
                    n--;
                    cnt[i]--;
                    char c = 'a' + i;
                    ans.push_back(c);
                }
            for( int i = 25 ; i >= 0 ; i-- )
                if(cnt[i]) {
                    n--;
                    cnt[i]--;
                    char c = 'a' + i;
                    ans.push_back(c);
                }
        }
        return ans;
    }
};