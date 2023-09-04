class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        string s[2] = {s1,s2};
        vector<char> chs[2][2];
        for( int i = 0 ; i < 2 ; i++ )
            for( int j = 0 ; j < n ; j++ )
                chs[i][j%2].push_back(s[i][j]);
        for( int i = 0 ; i < 2 ; i++ )
            for( int j = 0 ; j < 2 ; j++ )
                sort(chs[i][j].begin(),chs[i][j].end());
        return (chs[0][0] == chs[1][0]) and (chs[0][1] == chs[1][1]);
    }
};
