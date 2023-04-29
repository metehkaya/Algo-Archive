class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<vector<int>> nxt;
        nxt.push_back(vector<int>(26,-1));
        vector<bool> mark(1,false);
        int n = 1;
        for(string& s : words) {
            int node = 0;
            for(char ch : s) {
                int c = ch-'a';
                if(nxt[node][c] == -1) {
                    nxt[node][c] = n++;
                    nxt.push_back(vector<int>(26,-1));
                    mark.push_back(false);
                }
                node = nxt[node][c];
            }
            mark[node] = true;
        }
        vector<string> ans;
        for(string& s : words) {
            int len = s.length();
            vector<bool> dp(len+1,false);
            dp[len] = true;
            for( int i = len-1 ; i >= 0 ; i-- ) {
                int node = 0;
                for( int j = 0 ; j < len-1 && i+j < len ; j++ ) {
                    int c = s[i+j]-'a';
                    if(nxt[node][c] == -1)
                        break;
                    node = nxt[node][c];
                    if(dp[i+j+1] && mark[node]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if(dp[0])
                ans.push_back(s);
        }
        return ans;
    }
};
