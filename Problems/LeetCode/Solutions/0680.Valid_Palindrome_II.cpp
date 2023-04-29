typedef vector<bool> vb;
typedef vector<vb> vbb;

class Solution {
public:
    bool solve(int pass , int st , int n , string& s , vbb& mark) {
        int l = pass + (st == 1);
        int r = n-1 - pass - (st == 2);
        if(l >= r)
            return true;
        if(mark[pass][st])
            return false;
        mark[pass][st] = true;
        if(s[l] == s[r] && solve(pass+1,st,n,s,mark))
            return true;
        if(!st)
            if(solve(pass,1,n,s,mark) or solve(pass,2,n,s,mark))
                return true;
        return false;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        vbb mark(n,vb(3,false));
        return solve(0,0,n,s,mark);
    }
};