class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == 'B' and !st.empty() and st.top()=='A')
                st.pop();
            else if(c == 'D' and !st.empty() and st.top()=='C')
                st.pop();
            else
                st.push(c);
        }
        return (int) st.size();
    }
};
