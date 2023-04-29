typedef long long LL;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& ar) {
        int n = ar.size() , idx = 0;
        vector<int> st(n);
        for( int i = 0 ; i < n ; i++ ) {
            st[idx++] = ar[i];
            while(idx >= 2 && __gcd(st[idx-2],st[idx-1]) > 1) {
                st[idx-2] = (LL) st[idx-2]*st[idx-1] / __gcd(st[idx-2],st[idx-1]);
                idx--;
            }
        }
        st.resize(idx);
        return st;
    }
};
