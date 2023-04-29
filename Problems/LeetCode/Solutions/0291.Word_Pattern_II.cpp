class Solution {
public:
    int n,m;
    string t,s;
    unordered_set<string> used;
    unordered_map<char,string> mp;
    bool f(int i , int j) {
        if(i == n or j == m)
            return i == n and j == m;
        string s2 = "";
        if(mp.find(t[i]) == mp.end()) {
            for( int k = j+1 ; k <= m ; k++ ) {
                s2.push_back(s[k-1]);
                if(!used.count(s2)) {
                    used.insert(s2);
                    mp[t[i]] = s2;
                    if(f(i+1,k))
                        return true;
                    used.erase(s2);
                    mp.erase(t[i]);
                }
            }
        }
        else {
            s2 = mp[t[i]];
            int len = s2.length();
            if(j+len <= m and s.substr(j,len) == s2)
                return f(i+1,j+len);
        }
        return false;
    }
    bool wordPatternMatch(string t, string s) {
        this->t = t;
        this->s = s;
        n = t.length() , m = s.length();
        return f(0,0);
    }
};
