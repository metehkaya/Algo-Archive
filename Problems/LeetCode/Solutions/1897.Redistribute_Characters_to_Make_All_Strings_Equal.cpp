class Solution {
public:
    int cnt[26];
    bool makeEqual(vector<string>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int len = ar[i].length();
            for( int j = 0 ; j < len ; j++ )
                cnt[ar[i][j]-'a']++;
        }
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i]%n)
                return false;
        return true;
    }
};