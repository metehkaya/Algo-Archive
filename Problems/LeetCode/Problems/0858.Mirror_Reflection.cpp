class Solution {
public:
    int gcd(int a , int b) {
        if(!b)
            return a;
        return gcd(b,a%b);
    }
    int mirrorReflection(int p, int q) {
        int lcm = p*q / gcd(p,q);
        if((lcm/q) % 2 == 0)
            return 2;
        else {
            if(lcm % (2*p) == 0)
                return 0;
            else
                return 1;
        }
        return -1;
    }
};