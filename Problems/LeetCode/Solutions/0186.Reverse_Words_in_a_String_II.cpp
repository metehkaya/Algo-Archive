class Solution {
public:
    void reverseWords(vector<char>& s) {
        s.push_back(' ');
        int n = s.size();
        vector<char> v;
        stack<vector<char>> st;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == ' ') {
                if(!v.empty())
                    st.push(v);
                v.clear();
            }
            else
                v.push_back(s[i]);
        }
        s.clear();
        bool isFirst = true;
        while(!st.empty()) {
            if(!isFirst)
                s.push_back(' ');
            isFirst = false;
            v = st.top();
            st.pop();
            int sz = v.size();
            for( int i = 0 ; i < sz ; i++ )
                s.push_back(v[i]);
        }
    }
};