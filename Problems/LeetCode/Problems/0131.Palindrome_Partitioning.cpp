class Solution {
public:
    static const int maxn = 16;
    bool var[maxn][maxn];
    int n;
    string s;
    vector<string> v;
    vector<vector<string>> ans;
    void f(int idx) {
        if(idx == n) {
            ans.push_back(v);
            return;
        }
        string str = "";
        for( int i = idx ; i < n ; i++ ) {
            str.push_back(s[i]);
            if(var[idx][i]) {
                v.push_back(str);
                f(i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        this->s = s;
        n = s.length();
        memset(var,false,sizeof(var));
        for( int i = 0 ; i < n ; i++ ) {
            int l = i , r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                var[l][r] = true;
                l-- , r++;
            }
        }
        for( int i = 0 ; i+1 < n ; i++ ) {
            int l = i , r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                var[l][r] = true;
                l-- , r++;
            }
        }
        f(0);
        return ans;
    }
};