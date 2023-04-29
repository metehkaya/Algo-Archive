class Solution {
public:
    unsigned int n;
    map<unsigned int,int> dp;
    int f(unsigned int x) {
        if(x == 1)
            return 0;
        map<unsigned int,int>::iterator it = dp.find(x);
        if(it != dp.end())
            return it->second;
        int res;
        if(x % 2 == 0)
            res = dp[x] = f(x/2)+1;
        else
            res = dp[x] = min(f(x+1),f(x-1))+1;
        return res;
    }
    int integerReplacement(int n) {
        this->n = n;
        return f(this->n);
    }
};