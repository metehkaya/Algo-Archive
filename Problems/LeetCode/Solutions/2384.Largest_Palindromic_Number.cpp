class Solution {
public:
    string largestPalindromic(string s) {
        int n = s.length();
        vector<int> cnt(10,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'0']++;
        if(n == cnt[0])
            return "0";
        else if(cnt[0]+1 == n) {
            for( int i = 1 ; i < 10 ; i++ )
                if(cnt[i]) {
                    string ans = "";
                    ans.push_back('0'+i);
                    return ans;
                }
        }
        string t = "";
        for( int i = 9 ; i >= 0 ; i-- )
            for( int j = 0 ; j < cnt[i]/2 ; j++ )
                t.push_back('0'+i);
        string revt = t;
        reverse(revt.begin(),revt.end());
        for( int i = 9 ; i >= 0 ; i-- )
            if(cnt[i] % 2) {
                t.push_back('0'+i);
                break;
            }
        return t+revt;
    }
};
