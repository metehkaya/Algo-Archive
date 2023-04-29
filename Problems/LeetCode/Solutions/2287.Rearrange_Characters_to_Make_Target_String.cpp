class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        vector<int> scnt(26,0);
        vector<int> tcnt(26,0);
        for( int i = 0 ; i < s.length() ; i++ )
            scnt[s[i]-'a']++;
        for( int i = 0 ; i < t.length() ; i++ )
            tcnt[t[i]-'a']++;
        int ans = INT_MAX;
        for( int i = 0 ; i < 26 ; i++ )
            if(tcnt[i] > 0)
                ans = min(ans,scnt[i]/tcnt[i]);
        return ans;
    }
};
