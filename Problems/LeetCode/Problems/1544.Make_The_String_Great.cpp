class Solution {
public:
    string makeGood(string s) {
        int diff = 'a'-'A';
        while(s.length() >= 2) {
            int idx = -1;
            int n = s.length();
            for( int i = 0 ; i < n-1 ; i++ )
                if(s[i] >= 'a' && s[i] <= 'z' && s[i+1] == s[i]-diff) {
                    idx = i;
                    break;
                }
                else if(s[i] >= 'A' && s[i] <= 'Z' && s[i+1] == s[i]+diff) {
                    idx = i;
                    break;
                }
            if(idx == -1)
                break;
            s = s.substr(0,idx) + s.substr(idx+2,n-idx-2);
        }
        return s;
    }
};