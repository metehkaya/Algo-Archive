class Solution {
public:
    int numberOfBeams(vector<string>& ar) {
        int n = ar.size() , m = ar[0].length();
        int last = 0 , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int cnt = 0;
            for( int j = 0 ; j < m ; j++ )
                cnt += ar[i][j]-'0';
            if(!cnt)
                continue;
            ans += last*cnt;
            last = cnt;
        }
        return ans;
    }
};
