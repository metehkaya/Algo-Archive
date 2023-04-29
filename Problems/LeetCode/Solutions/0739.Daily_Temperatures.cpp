class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& ar) {
        stack<int> st;
        int n = ar.size();
        vector<int> ans(n,0);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            while(!st.empty() && ar[i] >= ar[st.top()])
                st.pop();
            if(!st.empty())
                ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};