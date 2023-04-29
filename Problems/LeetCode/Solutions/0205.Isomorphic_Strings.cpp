class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m)
            return false;
        vector<int>mapc(256,-1);
        vector<int>revmap(256,-1);
        for( int i = 0 ; i < n ; i++ ) {
            int a = (int) s[i];
            int b = (int) t[i];
            if(mapc[a] != -1 && mapc[a] != b)
                return false;
            if(revmap[b] != -1 && revmap[b] != a)
                return false;
            mapc[a] = b;
            revmap[b] = a;
        }
        return true;
    }
};