class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if( c == '(' || c == '{' || c == '[' )
                st.push(c);
            else if(st.empty())
                return false;
            else if( c == ')' ) {
                if(st.top() != '(')
                    return false;
                st.pop();
            }
            else if( c == '}' ) {
                if(st.top() != '{')
                    return false;
                st.pop();
            }
            else if( c == ']' ) {
                if(st.top() != '[')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};