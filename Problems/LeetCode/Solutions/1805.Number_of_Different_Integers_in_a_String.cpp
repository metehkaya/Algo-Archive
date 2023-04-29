class Solution {
public:
    int numDifferentIntegers(string s) {
        set<string> st;
        int n = s.length();
        for( int i = 0 ; i < n ; ) {
            if(s[i] >= '0' && s[i] <= '9') {
                int j = i;
                string t = "";
                bool add = false;
                while(j < n && s[j] >= '0' && s[j] <= '9') {
                    if(s[j] != '0')
                        add = true;
                    if(add)
                        t.push_back(s[j]);
                    j++;
                }
                i = j;
                st.insert(t);
            }
            else
                i++;
        }
        return st.size();
    }
};