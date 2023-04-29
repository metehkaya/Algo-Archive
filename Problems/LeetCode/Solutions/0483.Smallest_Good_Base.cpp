typedef long long LL;

class Solution {
public:
    const LL maxs = 1000001;
    bool check(LL n , LL b) {
        n--;
        LL curr = 1;
        while(n > 0) {
            if(n / curr >= b) {
                curr *= b;
                n -= curr;
            }
            else
                return false;
        }
        return n == 0;
    }
    string smallestGoodBase(string s) {
        LL n = 0;
        for(char c : s)
            n = 10*n + (c-'0');
        LL ans = n-1;
        LL root = sqrt(n);
        if(root > 1 and root*root + root + 1 == n)
            ans = root;
        for( LL b = 2 ; b < min(root,maxs) ; b++ )
            if(check(n,b)) {
                ans = b;
                break;
            }
        return to_string(ans);
    }
};
