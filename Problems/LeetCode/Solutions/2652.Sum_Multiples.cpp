class Solution {
public:
    int f(int n , int x) {
        int k = n/x;
        return x * k*(k+1)/2;
    }
    int sumOfMultiples(int n) {
        int ans = 0;
        ans += f(n,3) + f(n,5) + f(n,7) + f(n,105);
        ans -= f(n,15) + f(n,21) + f(n,35);
        return ans;
    }
};
