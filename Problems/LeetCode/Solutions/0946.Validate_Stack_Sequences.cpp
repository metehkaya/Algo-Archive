class Solution {
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        stack<int> st;
        int n = a.size();
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            st.push(a[i]);
            while(!st.empty() && st.top() == b[j])
                st.pop() , j++;
        }
        return st.empty();
    }
};