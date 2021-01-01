class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        vector<bool> valid(n,false);
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c >= 'a' && c <= 'z')
                valid[i] = true;
            else if(c == '(')
                st.push(i);
            else if(!st.empty()) {
                valid[st.top()] = true;
                valid[i] = true;
                st.pop();
            }
        }
        string ans = "";
        for( int i = 0 ; i < n ; i++ )
            if(valid[i])
                ans.push_back(s[i]);
        return ans;
    }
};