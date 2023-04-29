class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for( int b = 2 ; b <= n-2 ; b++ ) {
            int temp = n;
            vector<int> v;
            while(temp) {
                v.push_back(temp%b);
                temp /= b;
            }
            int sz = v.size();
            for( int i = 0 ; i < sz ; i++ )
                if(v[i] != v[sz-1-i])
                    return false;
        }
        return true;
    }
};
