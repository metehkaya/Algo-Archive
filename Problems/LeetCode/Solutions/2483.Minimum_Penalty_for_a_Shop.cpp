class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.length() , all = 0;
        for( int i = 0 ; i < n ; i++ )
            all += (s[i] == 'Y');
        int ans = 0 , best = all , cnt = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            cnt += (s[i-1] == 'Y');
            int score = (i-cnt) + (all-cnt);
            if(score < best)
                ans = i , best = score;
        }
        return ans;
    }
};
