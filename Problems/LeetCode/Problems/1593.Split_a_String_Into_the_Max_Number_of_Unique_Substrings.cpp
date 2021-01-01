#define mod 1000000007
typedef long long LL;

class Solution {
public:
    int f(int i , int n , string&s , set<LL>& ss) {
        if(i == n)
            return 0;
        int res = -1;
        LL curr = 0;
        for( int j = i ; j < n ; j++ ) {
            curr = 256*curr + s[j];
            curr %= mod;
            if(ss.count(curr) == 0) {
                ss.insert(curr);
                int temp = f(j+1,n,s,ss);
                if(temp != -1)
                    res = max(res,temp+1);
                ss.erase(curr);
            }
        }
        return res;
    }
    int maxUniqueSplit(string s) {
        int n = s.length();
        set<LL> ss;
        return f(0,n,s,ss);
    }
};