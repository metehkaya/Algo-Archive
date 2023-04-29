class Solution {
public:
    stack<int> st;
    int calPoints(vector<string>& ops) {
        int ans = 0 , n = ops.size();
        for( int i = 0 ; i < n ; i++ ) {
            string s = ops[i];
            if(s == "C")
                st.pop();
            else if(s == "D") {
                int x = st.top();
                st.push(2*x);
            }
            else if(s == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            }
            else {
                int x = stoi(s);
                st.push(x);
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};