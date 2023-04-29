class Solution {
public:
    int kthGrammar(int n, int k) {
        bool ans = false;
        k--;
        for( int i = n-2 ; i >= 0 ; i-- ) {
            bool right = (k&(1<<i)) > 0;
            ans ^= right;
        }
        return (int) ans;
    }
};
