class Solution {
public:
    int n;
    vector<bool> v;
    void parseStr(string& s) {
        s.push_back(',');
        int len = s.length();
        int i = 0 , val = 0;
        while(i < len) {
            if(s[i] == ',') {
                v.push_back(val >= 0);
                val = 0;
            }
            else if(s[i] == '#')
                val = -1;
            else
                val = 10*val + s[i]-'0';
            i++;
        }
        n = v.size();
    }
    bool dfs(int& idx) {
        if(idx == n)
            return false;
        bool lc = v[idx++];
        if(lc && !dfs(idx))
            return false;
        if(idx == n)
            return false;
        bool rc = v[idx++];
        if(rc && !dfs(idx))
            return false;
        return true;
    }
    bool isValidSerialization(string s) {
        if(s[0] == '#')
            return s.length() == 1;
        parseStr(s);
        int idx = 1;
        if(!dfs(idx))
            return false;
        return idx == n;
    }
};