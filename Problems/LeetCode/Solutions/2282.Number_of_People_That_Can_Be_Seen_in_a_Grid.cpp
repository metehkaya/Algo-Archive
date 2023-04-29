class Solution {
public:
    void sol(vector<vector<int>>& h , vector<vector<int>>& ans) {
        int n = h.size() , m = h[0].size();
        for( int i = 0 ; i < n ; i++ ) {
            stack<int> st;
            for( int j = m-1 ; j >= 0 ; j-- ) {
                int& cnt = ans[i][j];
                while(!st.empty()) {
                    int idx = st.top();
                    cnt++;
                    if(h[i][j] >= h[i][idx])
                        st.pop();
                    if(h[i][j] <= h[i][idx])
                        break;
                }
                st.push(j);
            }
        }
    }
    vector<vector<int>> seePeople(vector<vector<int>>& h) {
        int n = h.size() , m = h[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        sol(h,ans);
        vector<vector<int>> t_h(m,vector<int>(n));
        vector<vector<int>> t_ans(m,vector<int>(n));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                t_h[j][i] = h[i][j];
        sol(t_h,t_ans);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ans[i][j] += t_ans[j][i];
        return ans;
    }
};
