class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for( int i = 0 ; i < n/2 ; i++ ) {
            int j = n-1-i;
            int x = 2*i+1 , y = 2*j+1;
            ans += (y-x)/2;
        }
        return ans;
    }
};