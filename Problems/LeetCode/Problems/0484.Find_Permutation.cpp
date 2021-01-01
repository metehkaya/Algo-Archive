class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.length() , idx = 0;
        stack<int> st;
        vector<int> ans(n+1);
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == 'D')
                st.push(i+1);
            else {
                st.push(i+1);
                while(!st.empty()) {
                    ans[idx++] = st.top();
                    st.pop();
                }
            }
        st.push(n+1);
        while(!st.empty()) {
            ans[idx++] = st.top();
            st.pop();
        }
        return ans;
    }
};