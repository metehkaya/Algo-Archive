class Solution {
public:
    bool mark[26];
    int partitionString(string s) {
        int n = s.length() , ans = 1;
        memset(mark,false,sizeof(mark));
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'a';
            if(mark[c]) {
                ans++;
                memset(mark,false,sizeof(mark));
            }
            mark[c] = true;
        }
        return ans;
    }
};
