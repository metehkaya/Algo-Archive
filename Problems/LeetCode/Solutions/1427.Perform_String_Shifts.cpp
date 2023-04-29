class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        string ans = "";
        int n = s.length();
        int m = shift.size();
        int cnt = 0;
        for( int i = 0 ; i < m ; i++ ) {
            if(shift[i][0] == 0)
                cnt -= shift[i][1];
            else
                cnt += shift[i][1];
        }
        if(cnt < 0)
            cnt = -( (-cnt) % n );
        else
            cnt %= n;
        for( int i = 0 ; i < n ; i++ )
            ans.push_back(s[(i-cnt+n)%n]);
        return ans;
    }
};