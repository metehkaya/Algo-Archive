class Solution {
public:
    string smallestSubsequence(string s) {
        if(s == "")
            return s;
        vector<int>cnt(26,0);
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        string ans = "";
        vector<bool>var(26,false);
        for( int i = 0 ; i < n ; i++ ) {
            cnt[s[i]-'a']--;
            if(var[s[i]-'a'])
                continue;
            while( !ans.empty() && ( ans.back() == s[i] || ans.back() > s[i] && cnt[ans.back()-'a'] > 0 ) ) {
                var[ans.back()-'a'] = false;
                ans.pop_back();
            }
            var[s[i]-'a'] = true;
            ans.push_back(s[i]);
        }
        return ans;
    }
};