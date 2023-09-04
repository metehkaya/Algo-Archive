class Solution {
public:
    bool zero(string s) {
        for(char c : s)
            if(c == '0')
                return true;
        return false;
    }
    int check(string s, string t) {
        int n = s.length();
        int idx = n-1;
        int cost = n - zero(s);
        while(idx >= 0 and s[idx] != t[1])
            idx--;
        if(idx == -1)
            return cost;
        idx--;
        while(idx >= 0 and s[idx] != t[0])
            idx--;
        if(idx == -1)
            return cost;
        return n-idx-2;
    }
    int minimumOperations(string s) {
        int ans = check(s,"00");
        ans = min(ans,check(s,"25"));
        ans = min(ans,check(s,"50"));
        ans = min(ans,check(s,"75"));
        return ans;
    }
};
