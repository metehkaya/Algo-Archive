class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& ar) {
        int n = ar.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for( int k = 0 ; k < 2*n ; k++ ) {
            int i = k%n;
            while(!st.empty() && ar[st.top()] < ar[i]) {
                int idx = st.top();
                if(ans[idx] == -1)
                    ans[idx] = ar[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};