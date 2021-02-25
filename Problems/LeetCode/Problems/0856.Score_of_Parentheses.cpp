class Solution {
public:
    int other[50];
    int f(int l , int r) {
        if(l > r)
            return 0;
        if(r == l+1)
            return 1;
        if(other[l] == r)
            return 2*f(l+1,r-1);
        return f(l,other[l]) + f(other[l]+1,r);
    }
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int> st;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '(')
                st.push(i);
            else {
                int idx = st.top();
                st.pop();
                other[idx] = i;
                other[i] = idx;
            }
        return f(0,n-1);
    }
};