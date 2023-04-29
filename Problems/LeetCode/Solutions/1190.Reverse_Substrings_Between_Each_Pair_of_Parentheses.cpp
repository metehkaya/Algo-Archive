class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";
        int n = s.length();
        int k = 0;
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c == '(')
                st.push(k);
            else if(c == ')') {
                int index = st.top();
                st.pop();
                string l = ans.substr(0,index);
                string r = ans.substr(index,k-index);
                reverse(r.begin() , r.end());
                ans = l + r;
            }
            else
                ans.push_back(c) , k++;
        }
        return ans;
    }
};