class Solution {
public:
    static const int maxn = 100000;
    int l[maxn];
    int r[maxn];
    string pushDominoes(string s) {
        int n = s.length();
        for( int i = 0 , id = -1 ; i < n ; i++ ) {
            if(s[i] == 'R')
                id = i;
            else if(s[i] == 'L')
                id = -1;
            r[i] = id;
        }
        for( int i = n-1 , id = -1 ; i >= 0 ; i-- ) {
            if(s[i] == 'L')
                id = i;
            else if(s[i] == 'R')
                id = -1;
            l[i] = id;
        }
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            if(l[i] == -1 && r[i] == -1)
                ans.push_back('.');
            else if(l[i] == -1)
                ans.push_back('R');
            else if(r[i] == -1)
                ans.push_back('L');
            else {
                int dl = l[i]-i;
                int dr = i-r[i];
                if(dl == dr)
                    ans.push_back('.');
                else if(dl < dr)
                    ans.push_back('L');
                else
                    ans.push_back('R');
            }
        }
        return ans;
    }
};