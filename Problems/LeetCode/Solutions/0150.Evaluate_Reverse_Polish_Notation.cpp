class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                if(tokens[i] == "+")
                    st.push(x+y);
                else if(tokens[i] == "-")
                    st.push(x-y);
                else if(tokens[i] == "*")
                    st.push(x*y);
                else
                    st.push(x/y);
            }
            else {
                int x = stoi(tokens[i]);
                st.push(x);
            }
        }
        return st.top();
    }
};