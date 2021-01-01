class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string ans = "";
        stack<int> st;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == '(')
                st.push(i);
            else {
                int start = st.top();
                st.pop();
                if(st.empty()) {
                    int diff = i - start - 1;
                    ans += s.substr(start+1 , diff);
                }
            }
        }
        return ans;
    }
};