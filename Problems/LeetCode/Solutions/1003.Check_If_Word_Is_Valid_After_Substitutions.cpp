class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n % 3)
            return false;
        stack<char> st;
        for( int i = 0 , jump = 0 ; i < n ; i += jump ) {
            jump = 0;
            while(jump < 3 && i+jump < n && s[i+jump] == 'a'+jump)
                jump++;
            if(jump == 0) {
                if(st.empty())
                    return false;
                if(s[i++] != st.top())
                    return false;
                st.pop();
            }
            else if(jump == 1) {
                st.push('c');
                st.push('b');
            }
            else if(jump == 2)
                st.push('c');
        }
        return true;
    }
};