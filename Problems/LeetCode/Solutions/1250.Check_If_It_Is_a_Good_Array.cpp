class Solution {
public:
    int gcd(int a , int b) {
        if(!b)
            return a;
        return gcd(b,a%b);
    }
    bool isGoodArray(vector<int>& ar) {
        int g = ar[0];
        int n = ar.size();
        for( int i = 1 ; i < n ; i++ )
            g = gcd(g,ar[i]);
        return g == 1;
    }
};