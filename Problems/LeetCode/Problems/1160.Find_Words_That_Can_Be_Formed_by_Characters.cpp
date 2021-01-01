class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>cnt(26,0);
        for( int i = 0 ; i < chars.length() ; i++ )
            cnt[chars[i]-'a']++;
        int ans = 0;
        for( int i = 0 ; i < words.size() ; i++ ) {
            vector<int>cntRem = cnt;
            bool ok = true;
            for( int j = 0 ; ok && j < words[i].length() ; j++ ) {
                if(cntRem[words[i][j]-'a'] == 0)
                    ok = false;
                else
                    cntRem[words[i][j]-'a']--;
            }
            if(ok)
                ans += words[i].length();
        }
        return ans;
    }
};