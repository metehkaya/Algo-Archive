class Solution {
public:
    static const int maxv = 200001;
    bool var[maxv];
    int gcd(int x , int y) {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    int countDifferentSubsequenceGCDs(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            var[ar[i]] = true;
        for( int i = 1 ; i < maxv ; i++ ) {
            int g = 0;
            for( int j = i ; j < maxv ; j += i )
                if(var[j])
                    g = gcd(j,g);
            if(i == g)
                ans++;
        }
        return ans;
    }
};