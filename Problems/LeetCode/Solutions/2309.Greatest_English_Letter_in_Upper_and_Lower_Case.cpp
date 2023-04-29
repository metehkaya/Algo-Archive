class Solution {
public:
    string greatestLetter(string s) {
        int n = s.length();
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ )
            if(s[i] >= 'a')
                cnt[s[i]-'a'] |= 1;
            else
                cnt[s[i]-'A'] |= 2;
        string ans = "";
        for( int i = 25 ; i >= 0 ; i-- )
            if(cnt[i] == 3) {
                ans.push_back('A'+i);
                break;
            }
        return ans;
    }
};
