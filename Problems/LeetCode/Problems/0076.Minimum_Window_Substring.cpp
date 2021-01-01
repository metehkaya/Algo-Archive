class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = 0;
        string ans = "";
        int n = s.length();
        int m = t.length();
        vector<int> req(256,0);
        vector<int> curr(256,0);
        for( int i = 0 ; i < m ; i++ )
            req[t[i]]++;
        for( int i = 0 ; i < 256 ; i++ )
            cnt += !req[i];
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            if(i) {
                int c = s[i-1];
                if(curr[c]-- == req[c])
                    cnt--;
            }
            while(j < n && cnt < 256) {
                int c = s[j];
                if(++curr[c] == req[c])
                    cnt++;
                j++;
            }
            if(cnt == 256)
                if(ans.empty() || j-i < ans.length())
                    ans = s.substr(i,j-i);
        }
        return ans;
    }
};