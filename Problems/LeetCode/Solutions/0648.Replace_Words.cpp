class Solution {
public:
    static const int maxn = 100001;
    int N;
    bool var[maxn];
    int nxt[maxn][26];
    void f(int id , int idx , string& s) {
        if(idx == s.length()) {
            var[id] = true;
            return;
        }
        int c = s[idx]-'a';
        if(nxt[id][c] == -1)
            nxt[id][c] = ++N;
        f(nxt[id][c],idx+1,s);
    }
    int g(int id , int idx , string& s) {
        if(var[id])
            return idx;
        if(idx == s.length())
            return idx;
        int c = s[idx]-'a';
        if(nxt[id][c] == -1)
            return s.length();
        return g(nxt[id][c],idx+1,s);
    }
    string replaceWords(vector<string>& ar, string s) {
        memset(var,false,sizeof(var));
        memset(nxt,-1,sizeof(nxt));
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            f(0,0,ar[i]);
        s.push_back(' ');
        int m = s.length();
        string curr = "";
        string ans = "";
        for( int i = 0 ; i < m ; i++ ) {
            if(s[i] == ' ') {
                int len = g(0,0,curr);
                if(!ans.empty())
                    ans.push_back(' ');
                ans += curr.substr(0,len);
                curr = "";
            }
            else
                curr.push_back(s[i]);
        }
        return ans;
    }
};