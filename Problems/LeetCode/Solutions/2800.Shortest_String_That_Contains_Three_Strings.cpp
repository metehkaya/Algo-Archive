class Solution {
public:
    void f(string& s , string& t) {
        int lens = s.length();
        int lent = t.length();
        int len = min(lens,lent);
        if(lens >= lent)
            for( int i = 0 ; i <= lens-lent ; i++ )
                if(s.substr(i,lent) == t)
                    return;
        for( int l = len ; l >= 1 ; l-- )
            if(s.substr(lens-l,l) == t.substr(0,l)) {
                s += t.substr(l);
                return;
            }
        s += t;
    }
    string minimumString(string a, string b, string c) {
        string ans = "";
        int perm[3] = {0,1,2};
        string strs[3] = {a,b,c};
        do {
            string s = strs[perm[0]];
            f(s,strs[perm[1]]);
            f(s,strs[perm[2]]);
            if(ans == "" or s.length() < ans.length())
                ans = s;
            else if(s.length() == ans.length() and s < ans)
                ans = s;
        }while(next_permutation(perm,perm+3));
        return ans;
    }
};
