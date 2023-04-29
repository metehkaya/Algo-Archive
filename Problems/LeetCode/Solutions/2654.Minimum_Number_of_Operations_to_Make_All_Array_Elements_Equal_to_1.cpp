class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size() , n1 = 0;
        for(int x : v)
            n1 += (x == 1);
        if(n1)
            return n-n1;
        int minLen = INT_MAX;
        for( int i = 0 ; i < n ; i++ ) {
            int g = v[i];
            for( int j = i+1 ; j < n ; j++ ) {
                g = __gcd(g,v[j]);
                if(g == 1) {
                    minLen = min(minLen,j-i+1);
                    break;
                }
            }
        }
        return (minLen == INT_MAX) ? -1 : n+minLen-2;
    }
};
