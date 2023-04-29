class Solution {
public:
    string parseTernary(string s) {
        int n = s.length() , idx = 0;
        vector<char> st(n);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            char c = s[i];
            st[idx++] = c;
            if(idx >= 5 and st[idx-2] == '?') {
                int idx_val = (st[idx-1] == 'T') ? idx-3 : idx-5;
                st[idx-5] = st[idx_val];
                idx -= 4;
            }
        }
        return string(1, st[0]);
    }
};
