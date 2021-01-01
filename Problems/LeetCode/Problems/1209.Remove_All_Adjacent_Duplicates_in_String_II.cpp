typedef pair<char,int> pci;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pci> st;
        int n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(st.empty())
                st.push(pci(c,1));
            else {
                if(st.top().first == c) {
                    pci p = st.top();
                    st.pop();
                    p.second++;
                    st.push(p);
                }
                else
                    st.push(pci(c,1));
            }
            if(st.top().second == k)
                st.pop();
        }
        string ans = "";
        while(!st.empty()) {
            pci p = st.top();
            st.pop();
            for( int i = 0 ; i < p.second ; i++ )
                ans.push_back(p.first);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};