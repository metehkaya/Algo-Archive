class Solution {
public:
    string removeKdigits(string str, int k) {
        int n = str.length();
        vector<char> st;
        for( int i = 0 ; i < n ; i++ ) {
            char c = str[i];
            while(!st.empty() && k > 0 && st.back() > c)
                st.pop_back(), k--;
            st.push_back(c);
        }
        while(!st.empty() && k > 0)
            st.pop_back(), k--;
        string ans = "";
        bool found = false;
        for( int i = 0 ; i < st.size() ; i++ ) {
            if(!found && st[i] != '0')
                found = true;
            if(found)
                ans.push_back(st[i]);
        }
        if(!found)
            return "0";
        else
            return ans;
    }
};