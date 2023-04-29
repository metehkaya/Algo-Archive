class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(abs(n-m) > 1)
            return false;
        if(n > m) {
            swap(n,m);
            swap(s,t);
        }
        bool found = false;
        for( int i = 0 , j = 0 ; i < n && j < m ; ) {
            if(s[i] == t[j])
                i++,j++;
            else {
                if(found)
                    return false;
                if(n != m)
                    j++;
                else
                    i++,j++;
                found = true;
            }
        }
        if(n == m)
            return found;
        return true;
    }
};