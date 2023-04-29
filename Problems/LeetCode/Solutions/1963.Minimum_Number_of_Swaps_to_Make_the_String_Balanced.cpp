class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        stack<int> st;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '[')
                st.push(i);
        int ans = 0;
        for( int i = 0 , curr = 0 ; i < n ; i++ ) {
            if(s[i] == '[')
                curr++;
            else if(--curr < 0) {
                ans++;
                curr += 2;
                int idx = st.top();
                st.pop();
                swap(s[i],s[idx]);
            }
        }
        return ans;
    }
};