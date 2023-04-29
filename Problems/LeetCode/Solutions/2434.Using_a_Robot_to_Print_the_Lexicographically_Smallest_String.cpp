class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<int> last(26,-1);
        for( int i = 0 ; i < n ; i++ )
            last[s[i]-'a'] = i;
        string ans = "";
        stack<char> st;
        for( int i = 0 ; i < n ; i++ ) {
            st.push(s[i]);
            while(!st.empty()) {
                bool ok = true;
                char c = st.top();
                for( int j = 0 ; j < c-'a' ; j++ )
                    if(last[j] > i) {
                        ok = false;
                        break;
                    }
                if(!ok)
                    break;
                ans.push_back(c);
                st.pop();
            }
        }
        return ans;
    }
};
