class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        for( int times = 0 ; true ; times++ ) {
            bool ok = true;
            string t = s;
            for( int i = 0 ; i < n-1 ; i++ )
                if(s[i] == '0' && s[i+1] == '1') {
                    ok = false;
                    swap(t[i],t[i+1]);
                }
            if(ok)
                return times;
            s = t;
        }
        return -1;
    }
};
