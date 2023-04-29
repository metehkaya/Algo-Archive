class Solution {
public:
    bool check(string& s , string& t) {
        int lens = s.length();
        int lent = t.length();
        if(lens > lent)
            return false;
        if(lens == lent)
            return (s == t);
        int idx = 0;
        for( int i = 0 ; i < lent ; i++ )
            if(idx < lens && t[i] == s[idx])
                idx++;
        return idx == lens;
    }
    int findLUSlength(vector<string>& ar) {
        sort(ar.begin() , ar.end() , [&](string& s , string& t) {
            return s.length() > t.length();
        });
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = true;
            for( int j = 0 ; j < n ; j++ )
                if(j != i && check(ar[i],ar[j]))
                    ok = false;
            if(ok)
                return ar[i].length();
        }
        return -1;
    }
};