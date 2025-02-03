class Solution {
public:
    string findValidPair(string s) {
        int n = s.length();
        map<char,int> mp;
        for(char c : s)
            mp[c]++;
        for( int i = 0 ; i < n-1 ; i++ )
            if(s[i] != s[i+1])
                if(mp[s[i]] == s[i]-'0')
                    if(mp[s[i+1]] == s[i+1]-'0')
                        return s.substr(i,2);
        return "";
    }
};