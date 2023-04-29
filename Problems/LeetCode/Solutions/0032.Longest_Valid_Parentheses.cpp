class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        int idx[n];
        memset(idx,-1,sizeof(idx));
        stack<int> st;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == '(')
                st.push(i);
            else if(!st.empty()) {
                int id = st.top();
                idx[id] = i;
                st.pop();
            }
        }
        int ans = 0;
        int dp[n];
        memset(dp,0,sizeof(dp));
        for( int i = n-1 ; i >= 0 ; i-- )
            if(idx[i] != -1) {
                int j = idx[i];
                int add = (j+1 < n) ? dp[j+1] : 0;
                dp[i] = (j-i+1) + add;
                ans = max(ans,dp[i]);
            }
        return ans;
    }
};