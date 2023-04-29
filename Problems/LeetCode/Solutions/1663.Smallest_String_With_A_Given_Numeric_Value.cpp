class Solution {
public:
    string getSmallestString(int n, int k) {
        string s = "";
        for( int i = 0 ; i < n ; i++ )
            s.push_back('a');
        k -= n;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int add = min(k,25);
            k -= add;
            s[i] += add;
        }
        return s;
    }
};