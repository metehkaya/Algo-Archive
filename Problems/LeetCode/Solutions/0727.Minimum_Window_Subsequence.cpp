class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length() , m = t.length();
        vector<int> curr(26,-1);
        vector<vector<int>> nxt(n);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            nxt[i] = curr;
            curr[s[i]-'a'] = i;
        }
        string ans = "";
        for( int k = 0 ; k < n ; k++ )
            if(s[k] == t[0]) {
                int i=k , j=0;
                while(j < m-1 && i != -1)
                    i = nxt[i][t[++j]-'a'];
                if(i == -1)
                    continue;
                string temp = s.substr(k,i-k+1);
                if(ans.empty() || temp.length() < ans.length())
                    ans = temp;
            }
        return ans;
    }
};