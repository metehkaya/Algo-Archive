class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int len = path.length();
        string dir = "";
        for( int i = 0 ; i < len ; i++ ) {
            if( path[i] == '/' ) {
                if( dir != "" ) {
                    if( dir == ".." ) {
                        if( !st.empty() )
                            st.pop();
                    }
                    else if( dir != "." )
                        st.push(dir);
                }
                dir = "";
            }
            else
                dir = dir + path[i];
        }
        if(dir != "") {
            if(dir == "..") {
                if( !st.empty() )
                    st.pop();
            }
            else if( dir != "." )
                st.push(dir);
        }
        string ans = "";
        if(st.empty())
            ans = "/";
        else {
            vector<string> v;
            while(!st.empty()) {
                v.push_back(st.top());
                st.pop();
            }
            reverse(v.begin(), v.end());
            for( int i = 0 ; i < (int) v.size() ; i++ )
                ans += "/" + v[i];
        }
        return ans;
    }
};