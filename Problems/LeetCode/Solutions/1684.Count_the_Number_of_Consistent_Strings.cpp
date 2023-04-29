class Solution {
public:
    bool var[256];
    int countConsistentStrings(string allowed, vector<string>& ar) {
        int len = allowed.length();
        for( int i = 0 ; i < len ; i++ )
            var[allowed[i]] = true;
        int ans = 0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int add = 1;
            len = ar[i].length();
            for( int j = 0 ; j < len ; j++ )
                if(!var[ar[i][j]])
                    add = 0;
            ans += add;
        }
        return ans;
    }
};