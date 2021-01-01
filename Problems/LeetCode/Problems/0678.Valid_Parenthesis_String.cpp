class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int lo = 0 , hi = 0;
        for( int i = 0 ; i < n ; i++ ) {
        	if(s[i] == '(')
        		lo++,hi++;
        	else if(s[i] == ')')
        		lo--,hi--;
        	else
        		lo--,hi++;
        	if(hi < 0)
        		return false;
        	lo = max(lo,0);
        }
        return lo == 0;
    }
};