class Solution {
public:
    long long ans;
    void f(long long p , int mult) {
        long long val = p >= 2 ? p*(p-1)/2 : 0;
        ans += mult*val;
    }
    long long distributeCandies(int n, int limit) {
        f(n+2-0*(limit+1),1);
        f(n+2-1*(limit+1),-3);
        f(n+2-2*(limit+1),3);
        f(n+2-3*(limit+1),-1);
        return ans;
    }
};
